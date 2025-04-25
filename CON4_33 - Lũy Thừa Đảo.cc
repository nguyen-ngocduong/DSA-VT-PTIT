#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long bin_pow(long long a, long long b){
    if(b == 1) return a;
    long long tmp = bin_pow(a,b/2);
    if(b%2 == 1) return (((tmp%MOD)*tmp%MOD)*a)%MOD;
    return ((tmp%MOD)*tmp%MOD);
}
int main(){
    int t; cin >> t;
    while(t--){
        string s1; cin >> s1;
        string s2 = s1;
        reverse(begin(s2), end(s2));
        long long n1 = stoll(s1);
        long long n2 = stoll(s2);
        long long ans = bin_pow(n1,n2);
        cout << ans % MOD << endl;
    }
    return 0;
}