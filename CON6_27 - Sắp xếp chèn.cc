#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            int new_number = a[i];
            int pos = i - 1;
            while(pos >= 0 && a[pos] > new_number){
                a[pos+1] = a[pos];
                pos -= 1;
            }
            a[pos+1] = new_number;
            cout << "Buoc "<< i << ": ";
            for(int k = 0; k <= i; k++){
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}