#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5+3;
int n;
vector<int> dis;
vector<int> prt;
vector<pair<int, int>> adj[N];
vector<pair<int, pair<int, int>>> edges;

void add_undirected_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edges.push_back({w, {u, v}});
}

void bellman_ford(int src) {
    dis.assign(n, INF);
    prt.assign(n, -1);
    dis[src] = 0;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;
            if (dis[u] != INF && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                prt[u] = v;
            }
        }
    }
    for (auto e : edges) {
        int u = e.second.first;
        int v = e.second.second;
        int w = e.first;
        if (dis[u] != INF && dis[v] > dis[u] + w) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }
}

int main() {
    cin >> n;
    int q;
    cin >> q;
    while (q > 0) {
        int u, v, w;
        cin >> u >> v >> w;
        add_undirected_edge(u, v, w);
        q--;
    }
    bellman_ford(0);

    cout << "disance :\n";
    for (int i = 0; i < n; i++) 
        cout << i << ' ' << dis[i] << '\n'; 
    cout << '\n';
    cout << "Parent :\n";
    for (int i = 0; i < prt.size(); i++) 
        cout << i << ' ' << prt[i] << '\n'; 
    cout << '\n';
}
/*
5
8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
*/
/*
disance :
0 0
1 -1
2 2
3 -2
4 1

Parent :
0 2
1 4
2 -1
3 -1
4 3
*/
