//Amswer of problem's cses (Company Queries I)

#include <bits/stdc++.h>
using namespace std;

#define ll long long


const int LOG = 30;
const int N = 2e5+10;

int par[N];
int up[LOG][N];

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
    }
    for (int i = 2; i <= n; i++)up[0][i] = par[i];

    for (int pw = 1; pw < LOG; pw++) {
        for (int i = 2; i <= n; i++) {
            up[pw][i] = up[pw - 1][up[pw - 1][i]];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < LOG; i++) {
            if(k>>i&1) {
                x=up[i][x];
            }
        }
        if(x)cout<<x<<endl;
        else cout<<-1<<endl;
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
