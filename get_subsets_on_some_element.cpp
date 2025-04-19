#include <bits/stdc++.h>
using namespace std;
vector<int> subset;
void Generating_Subsets_on_some_Element(int i, vector<int> &arr, int n) {
    if (i == n) {
        cout << "{";
        for (int j = 0; j < subset.size(); j++) {
            cout << subset[j];
            if (j < subset.size() - 1) cout << ",";
        }
        cout << "}" << endl;
        return;
    }

    Generating_Subsets_on_some_Element(i + 1, arr, n);
    subset.push_back(arr[i]);
    Generating_Subsets_on_some_Element(i + 1, arr, n);
    subset.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Generating_Subsets_on_some_Element(0, arr, n);
    return 0;
}
