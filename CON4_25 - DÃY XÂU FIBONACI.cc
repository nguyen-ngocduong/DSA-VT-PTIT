#include<bits/stdc++.h>
using namespace std;
int main () {
    int tc; cin>>tc;
    while(tc--) {
        long long n,k; cin>>n>>k;
        long long a[n+1];
        a[1] =1; a[2] =1;
        for(int i = 3; i<=n; i++){
            a[i] = a[i-1] + a[i-2];
        }
        while(true) {
            if(n==1) {
                cout<<"A"<<endl;
                break;
            }
            else if(n == 2) {
                cout<<"B" <<endl;
                break;
            }
            if(k > a[n-2]) {
                k -= a[n-2];
                n--; // giảm đến khi nào k = 1 or k = 2 thì dừng
            }
            else {
                n -= 2;
            }
        }
    }
    return 0;
}