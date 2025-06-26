#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int LOG = 30;
vector<int> par, depth;
vector<vector<int> > adj;
int up[LOG][N];

void dfs(int u, int p = -1, int d = 0) {
    depth[u] = d;
    par[u] = p;
    for (int v: adj[u]) {
        if (v == p)continue;
        up[0][v] = u;
        for (int i = 1; i < LOG; i++) {
            up[i][v] = up[i - 1][up[i - 1][v]];
        }
        dfs(v, u, d + 1);
    }
}

int k_th_ancestor(int k, int u) {
    for (int i = 0; i < LOG; i++) {
        if (k >> i & 1) {
            u = up[i][u];
        }
    }
    return u;
}

int get_LCA(int u, int v) {
    if (depth[u] < depth[v])swap(u, v);

    int k = depth[u] - depth[v];

    u = k_th_ancestor(k, u);

    if (u == v)return v;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][v];
}

void solve() {
    int n, q;
    cin >> n >> q;
    adj = vector<vector<int> >(n + 1);
    par = depth = vector<int>(n + 1);

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(1);

    while (q--) {
        int u, v, x, y;
        cin >> u >> v;
        x = u, y = v;
        int l = get_LCA(u, v);
        int ans = depth[x] - 2*depth[l] + depth[y];
        cout << ans << endl;
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
