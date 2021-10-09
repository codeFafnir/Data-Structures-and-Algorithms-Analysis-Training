#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5+3;
int n;
vector<int> dis;
vector<int> prt;
vector<pair<int, int>> adj[N];
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int, int>>> res;

void add_undirected_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edges.push_back({w, {u, v}});
}

void kruskal() {
    vector<int> vertex_id(n);
    for (int i = 0; i < n; i++)
        vertex_id[i] = i;
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        int old_id = vertex_id[e.second.first];
        int new_id = vertex_id[e.second.second];
        if (old_id == new_id)
            continue;
        res.push_back(e);
        for (int i = 0; i < n; i++) {
            if (vertex_id[i] == old_id)
                vertex_id[i] = new_id;
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
    kruskal();

    cout << "kruskal :\n";
    for (auto i : res) 
        cout << i.second.first << ' ' << i.second.second << ' ' << i.first << '\n'; 
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
kruskal :
6 7 1
2 8 2
5 6 2
0 1 4
2 5 4
2 3 7
0 7 8
3 4 9
*/
