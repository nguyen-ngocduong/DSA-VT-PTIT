#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin>>n;
        int a[n],b[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        int pos1,pos2;
        sort(a,a+n);
        for(int i = 0; i<n; i++){
            if(a[i] != b[i]){
                pos1 = i;
                break;
            }
        }
        for(int j = n-1; j>= 0; j--){
            if(a[j] != b[j]){
                pos2 = j;
                break;
            }
        }
        cout << pos1 +1 << " " << pos2 + 1 << endl;
    }
    return 0;
}