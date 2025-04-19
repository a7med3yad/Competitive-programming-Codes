void Generating_Subsets(int i) {
    if (i == n) {
        cout<<"{";
        for (auto it:v)cout << it << ',';
        cout <<"}"<<endl;
        return;
    }
    Generating_Subsets(i + 1);
    v.push_back(i);
    Generating_Subsets(i + 1);
    v.pop_back();
}
