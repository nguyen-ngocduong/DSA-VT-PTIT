#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int bin_pow(long long n, long long k){
    long long res = 1;
    while(k){
        if(k%2 == 1){
            res = (res*n) %MOD; 
        }
        n = (n*n) % MOD;
        k/=2;
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        long long ans = bin_pow(n,k);
        cout << ans%MOD << endl;
    }
    return 0;
}