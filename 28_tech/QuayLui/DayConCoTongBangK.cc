#include<bits/stdc++.h>
using namespace std;
int a[100], x[100], n,s, ok;
void show(int m){
    ok = 1;
    cout << "[";
    for(int i = 1; i<m; i++){
        cout << x[i] << " ";
    }
    cout << x[m] << "] ";
}
void Try(int i, int pos, int sum){
    for(int j = pos; j <= n; j++){
        if(sum + a[j] > s) return;
        x[i] = a[j];
        if(sum + a[j] == s) show(i);
        Try(i+1, j+1, sum + a[j]);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 1; i<=n; i++) cin >> a[i];
        sort(a+1, a+ n +1);
        ok = 0;
        Try(1,1,0);
        if(ok == 0) cout << -1;
        cout << endl;
    }
    return 0;
}