#include<bits/stdc++.h>
using namespace std;
int a[51];
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        memset(a, 0, sizeof(a));
        a[0] = a[1] = 1;
        for(int i = 2; i<=n; i++){
            if(i-1 >= 0) a[i] += a[i-1];
            if(i-2 >= 0) a[i] += a[i-2];
            if(i-3 >= 0) a[i] += a[i-3];
        }
        cout << a[n] << endl;
    }
    return 0;
}