#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> permutation;
vector<bool> used;

void Generating_Permutation() {
    if ((int) permutation.size() == n) {
        cout << "{";
        for (int i = 0; i < n; i++) {
            cout << permutation[i];
            if (i != n - 1) cout << ",";
        }
        cout << "}" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        permutation.push_back(i);
        Generating_Permutation();
        used[i] = false;
        permutation.pop_back();
    }
}

int main() {
    cin >> n;
    used.assign(n, false);
    Generating_Permutation();
    return 0;
}
