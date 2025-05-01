#include<bits/stdc++.h>
using namespace std;
long long bin_pow(long long a, long long b){
    long long tmp = pow(2, a-1);
    if(b == tmp) return a;
    if(b > tmp){
        return bin_pow(a-1, 2*tmp - b);
    }
    return bin_pow(a-1, b);
}
int main(){
    int t; cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        cout << bin_pow(n,k) << endl;
    }
    return 0;
}