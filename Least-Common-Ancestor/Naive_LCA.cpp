// answer of problem's cses (company queries II)
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
 
vector<int> par, depth;
vector<vector<int> > adj;
 
void dfs(int u, int p = -1, int d = 0) {
    depth[u] = d;
    par[u] = p;
    for (int v: adj[u]) {
        if (v == p)continue;
        dfs(v, u, d + 1);
    }
}
 
int lca(int u, int v) {
    if (depth[u] < depth[v])swap(u, v);
    while (depth[u] != depth[v]) {
        u = par[u];
    }
    while (u != v) {
        u = par[u];
        v = par[v];
    }
    if (v != u)return -1;
    return u;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    adj = vector<vector<int> >(n + 1);
    par = depth = vector<int>(n + 1);
 
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
 
    dfs(1);
 
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
 
    solve();
    return 0;
}
