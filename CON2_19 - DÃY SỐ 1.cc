#include<bits/stdc++.h>
using namespace std;
int a[100];
void Dequy(int n){
    if(n == 0) return;
    cout << "[";
    for(int j = 0; j<n-1; j++){
        cout << a[j] << " ";
    }
    cout << a[n-1] << "]"<< endl;
    for(int k = 0; k<n-1; k++){
        a[k] = a[k] + a[k+1];
    }
    Dequy(n-1);
}
int main (){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i<n; i++){
            cin >>a[i];
        }
        Dequy(n);
    }
    return 0;
}