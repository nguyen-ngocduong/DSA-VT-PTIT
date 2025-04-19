#include<bits/stdc++.h>
using namespace std;
int a[1005], n, s, X[1005], ok;
void init(){
    cin >> n >> s;
    ok = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
}
void Try(int i, int sum, int pos){
    if(sum == s){
        cout << "[";
        for(int j = 1; j<i; j++){
            cout << X[j];
            if(j < i - 1) cout << " ";
        }
        cout << "] ";
        ok = 1;
        return;
    }
    for(int j = pos; j <= n; j++){
        if(sum + a[j] <= s){
            X[i] = a[j];
            Try(i+1, sum + a[j], j);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        Try(1,0,1);
        if(!ok) cout << -1 << endl;
        else cout << endl;
    }
    return 0;
}