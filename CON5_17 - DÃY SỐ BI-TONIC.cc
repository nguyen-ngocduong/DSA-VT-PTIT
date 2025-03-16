#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t; 
    while (t--)
    {
        int n; cin >> n;
        int a[n],l[n],r[n], res = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            l[i] = a[i];
            for(int j = 0; j<i; j++){
                if(a[i] > a[j]) l[i] = max(l[i], l[j] + a[i]);
            }
        }
        for(int i = n-1; i>=0; i--){
            r[i] = a[i];
            for(int j = i+1; j<n; j++){
                if(a[i] > a[j]) r[i] = max(r[i], r[j] + a[i]);
            }
            res = max(res, l[i] + r[i] - a[i]);
        }
        cout << res << endl;
    }
    return 0;
}