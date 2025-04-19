#include<bits/stdc++.h>
using namespace std;
int n, X[100];
vector<vector<int>> res;
void init(){
    cin >>n;
    res.clear();
}
void Try(int sum, int i, int pos){
    if(sum == n){
        vector<int> tmp(X+1,X+i);
        res.push_back(tmp);
        return;
    }
    for(int j = pos; j>=1; j--){
        if(sum + j <= n){
            X[i] = j;
            Try(sum+j, i+1, j);
        }
    }
}
void solve(){
    init();
    Try(0,1,n);
    cout << res.size() << endl;
    for(auto value : res){
        cout << "(";
        for(int i = 0; i<value.size(); i++){
            cout << value[i];
            if(i != value.size() - 1) cout << " ";
            else cout << ") ";
        }
    }
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}