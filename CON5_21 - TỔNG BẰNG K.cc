#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[1001];
        for(int i = 1; i<=n; i++) cin >> a[i];
        long long tmp[1001] = {0};
        tmp[0] = 1;
        for(int i = 1; i<= k; i++) {
            for(int j = 1; j<= n; j++) {
                if(i >= a[j]) {
                    tmp[i] = (tmp[i] + tmp[i - a[j]]) % MOD;
                }
            }
        }
        cout << tmp[k] << endl;
    }
    return 0;
}