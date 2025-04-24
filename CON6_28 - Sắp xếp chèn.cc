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
        vector<int> res[n];
        for(int i = 0; i<n; i++){
            int new_number = a[i];
            int pos = i-1;
            while(pos >= 0 && a[pos] > new_number){
                a[pos+1] = a[pos];
                pos -= 1;
            }
            a[pos+1] = new_number;
            for(int k = 0; k<=i; k++){
                res[i].push_back(a[k]);
            }
        }
        for(int i = n-1; i>=0; i--){
            cout << "Buoc " << i << ": ";
            for(int j = 0; j<res[i].size(); j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}