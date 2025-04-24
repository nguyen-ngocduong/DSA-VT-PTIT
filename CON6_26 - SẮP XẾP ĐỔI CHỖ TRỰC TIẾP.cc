#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(a[i] > a[j]) {
                    swap(a[i],a[j]);
                }
            }
            cout << "Buoc " << i+1 << ": ";
            for(int k = 0; k<n; k++){
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}