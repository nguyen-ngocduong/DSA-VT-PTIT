#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int X[100];
int ans;
void init(){
    cin >> n >> k >> s;
}
void Try(int i){
    for(int j = X[i - 1] + 1; j <= n - k + i; j++){
        X[i] = j;
        if(i == k){
            int sum = 0;
            for(int j = 1; j <= k; j++) {
                sum += X[j];
            }
            if(sum == s) ans++;
        }
        else{
            Try(i+1);
        }
    }
}
int main(){
    while(1){
        init();
        if(n + k + s == 0) {
            break;
        }
        else {
            ans = 0;
            Try(1);
            cout << ans << endl;
        }
    }
    return 0;
}