#include<bits/stdc++.h>
using namespace std;
int main () {
    int t; cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i = 1; i<=k; i++) {
            cin >> a[i];
        }
        int i = k;
        while(i > 0 && a[i] == n - k + i){
            i--;
        }
        if(i == 0){
            for(int i = 1; i<=k; i++){
                cout << i << " ";
            }
        }
        else{
            a[i]++;
            for(int j = i+1; j<=k; j++) {
                a[j] = a[j-1] + 1;
            }
            for(int i = 1; i<=k; i++) cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}