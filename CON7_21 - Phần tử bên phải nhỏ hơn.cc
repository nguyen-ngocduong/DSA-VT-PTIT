#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n+1];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        int i = 0;
        while(i < n){
            int ok = 0;
            for(int j = i+1; j<n; j++){
                if(a[j] > a[i]){
                    for(int k = j+1; k<n; k++){
                        if(a[k] < a[j]){
                            ok = 1;
                            cout << a[k]<<" ";
                            break;
                        }
                    }
                    break;
                }
            }
            if(ok == 0) cout << -1 << " ";
            i++;
        }
        cout << endl;
    }
    return 0;
}