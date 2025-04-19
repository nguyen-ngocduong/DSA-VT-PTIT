#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005], cnt = 0, res = 0;
void init(){
    cin >> n >> m;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            cin >> a[i][j];
        }
    }
}
void Try(int i, int j, int sum){
    if(i == n && j == m){
        cnt++;
        res = max(sum, res);
        return;
    }
    if(i+1 <= n){
        sum += a[i+1][j];
        Try(i+1,j, sum);
        sum -= a[i+1][j];
    }
    if(j+1 <= m){
        sum += a[i][j+1];
        Try(i,j+1,sum);
        sum -= a[i][j+1];
    }
}
int main(){
    int t; cin >>t;
    while (t--)
    {
        init();
        cnt = 0;
        res = 0;
        Try(1,1,a[1][1]);
        cout << cnt << " " << res << endl;
    }
    return 0;
}