#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets;
void Generating_subsets(int n) {
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(j + 1);//1 based
            }
        }

        subsets.push_back(subset);
    }
}
int main() {
    int n;
    cin >> n;
    Generating_subsets(n);
    for (int i = 0; i < subsets.size(); i++) {
        cout<<"{";
        for (int j = 0; j < subsets[i].size(); j++) {
            if(j!=subsets[i].size()-1)cout << subsets[i][j] << ",";
            else cout << subsets[i][j];
        }
        cout <<"}"<< endl;
    }
    return 0;
}
