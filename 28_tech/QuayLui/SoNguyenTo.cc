#include<bits/stdc++.h>
using namespace std;
int n,p,s, X[1005];
vector<int> nto;
vector<vector<int>> res;
bool prime(int n){
    if(n < 2) return false;
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}
void init(){
    nto.clear();
    res.clear();
    cin >> n >> p >> s;
    for(int i = p+1; i<=s; i++){
        if(prime(i)) nto.push_back(i);
    }
}
void Try(int i, int sum, int pos){
    if(i == n && sum == s){
        vector<int> v(X, X+n);
        res.push_back(v);
    }
    for(int j = pos; j<=nto.size();j++){
        if(sum + nto[j] <= s){
            X[i] = nto[j];
            Try(i+1, sum +nto[j], j + 1);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        Try(0,0,0);
        cout << res.size() << endl;
        for(auto value : res){
            for(int x : value){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}