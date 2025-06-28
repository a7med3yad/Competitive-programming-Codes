#include <bits/stdc++.h>
using namespace std;

const int LOG = 18;

vector<vector<pair<int, int>>> adj;

class LeastCommonAncestor {
public:
    int Iden;
    function<int(int, int)> fn;
    int n;
    vector<int> depth, par;
    vector<vector<int>> ances, cost;

    LeastCommonAncestor(int n, int iden, function<int(int, int)> func) {
        this->n = n;
        Iden = iden;
        fn = func;

        depth.assign(n + 1, 0);
        par.assign(n + 1, -1);
        ances.assign(LOG, vector<int>(n + 1, -1));
        cost.assign(LOG, vector<int>(n + 1, Iden));
    }

    void dfs(int u, int p = -1, int d = 0, int w = 0) {
        depth[u] = d;
        par[u] = p;
        ances[0][u] = p;
        cost[0][u] = w;

        for (int i = 1; i < LOG; i++) {
            if (ances[i - 1][u] == -1) break;
            ances[i][u] = ances[i - 1][ances[i - 1][u]];
            cost[i][u] = fn(cost[i - 1][u], cost[i - 1][ances[i - 1][u]]);
        }

        for (auto [v, w] : adj[u]) {
            if (v != p)
                dfs(v, u, d + 1, w);
        }
    }

    int k_th_ancestor(int u, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                u = ances[i][u];
                if (u == -1) break;
            }
        }
        return u;
    }

    int get_LCA(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        u = k_th_ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (ances[i][u] != -1 && ances[i][u] != ances[i][v]) {
                u = ances[i][u];
                v = ances[i][v];
            }
        }
        return ances[0][u];
    }

    int get_cost(int u, int v) {
        int lca = get_LCA(u, v);
        return fn(path_cost(u, lca), path_cost(v, lca));
    }

private:
    int path_cost(int u, int anc) {
        int ret = Iden;
        int k = depth[u] - depth[anc];
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                ret = fn(ret, cost[i][u]);
                u = ances[i][u];
            }
        }
        return ret;
    }
};

void solve() {
    int n, q;
    cin >> n;

    adj.assign(n + 1, {});

    for (int i = 0, u, v, w; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    LeastCommonAncestor mx(n, -1e5+5, [](int a, int b) { return max(a, b); });

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int MX = mx.get_cost(u, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int tc;
    //cin >> tc;
    //for (int i = 1; i <= tc; i++) {
        solve();
    //}
    return 0;
}
