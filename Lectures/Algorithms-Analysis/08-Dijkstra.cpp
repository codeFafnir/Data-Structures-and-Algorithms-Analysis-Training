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

void dijkstra(int src) {
    dis.assign(n, INF);
    prt.assign(n, -1);
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>> > pq;     
    pq.push({0, src}); 
    dis[src] = 0;
    while (!pq.empty()) { 
        int v = pq.top().second; 
        pq.pop();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dis[u] > dis[v] + w) {
                dis[u] = dis[v] + w;
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
    dijkstra(0);

    cout << "Distance :\n";
    for (int i = 0; i < n; i++) 
        cout << i << ' ' << dis[i] << '\n'; 
    cout << '\n';
    cout << "Parent :\n";
    for (int i = 0; i < prt.size(); i++) 
        cout << i << ' ' << prt[i] << '\n'; 
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
Distance :
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14

Parent :
0 -1
1 0
2 1
3 2
4 5
5 6
6 7
7 0
8 2
*/
