#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int X[100];
int ans;
void Dequy(int i){
    for(int j = 1 + X[i-1]; j <= n-k+i; j++){
        X[i] = j;
        if(i == k){
            int res = 0;
            for(int m = 1; m <= k; m++){
                res += X[m];
            }
            if(res == s) ans++;
        }
        else Dequy(i+1);
    }
}
int main(){
    while(true){
        cin >> n >> k >> s;
        X[0] = 0;
        ans = 0;
        Dequy(1);
        cout << ans << endl;
    }
    return 0;
}