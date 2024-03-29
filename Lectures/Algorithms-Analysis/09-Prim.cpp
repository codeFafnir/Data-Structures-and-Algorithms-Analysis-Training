#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5+3;
int n;
vector<int> dis;
vector<int> prt;
vector<pair<int, int>> adj[N];

void add_undirected_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void prim(int src) {
    dis.assign(n, INF);
    prt.assign(n, -1);
    vector<bool> vis(n, 0);
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>> > pq;     
    pq.push({0, src}); 
    dis[src] = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        vis[v] = 1;
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (vis[u] == 0 && dis[u] > w) {
                dis[u] = w;
                pq.push({dis[u], u});
                prt[u] = v;
            }
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
    prim(0);
    
    cout << "Prim :\n";
    for (int i = 1; i < n; i++) 
        cout << i << ' ' << prt[i] << ' ' << dis[i] << '\n'; 
    cout << '\n';
}
/*
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
/*
Prim :
1 0 4
2 1 8
3 2 7
4 3 9
5 2 4
6 5 2
7 6 1
8 2 2
*/