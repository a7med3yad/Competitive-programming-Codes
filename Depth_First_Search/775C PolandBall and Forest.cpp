#include <bits/stdc++.h>
using namespace std;

const int LOG = 18;
const int N = 1e5 + 5;

vector<vector<int> > adj;
int vis[N];

void init(int n) {
    adj.assign(n, {});
    fill(vis, vis + n, 0);
}

void dfs(int u ) {
    vis[u]=1;
    for (int v: adj[u]) {
        if(!vis[v])dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;
    init(n + 1);

    for (int i = 1,x; i <= n; i++) {
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    int cnt=0;
    for (int i=1;i<=n;i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<endl;

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
