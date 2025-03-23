#include<bits/stdc++.h>
using namespace std;
int main () {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        int sum = 0;
        for(int i = 0; i< n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2 == 1){
            cout << "NO" << endl;
        }
        else{
            sum /= 2;
            vector<int> v(sum+1, 0);
            for(int i = 0; i<n; i++) {
                for(int j = sum; j >= a[i]; j--){
                    if(v[j - a[i]]){
                        v[j] = 1;
                    }
                }
            }
            cout << "YES" << endl;
        }
    }
    return 0;
}