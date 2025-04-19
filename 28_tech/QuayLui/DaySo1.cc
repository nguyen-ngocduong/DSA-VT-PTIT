#include<bits/stdc++.h>
using namespace std;
int X[100];
int n;
void init(){
    for (int i = 1; i <= n; i++)
    {
        cin >>X[i];
    }
}
void Try(int n){
    if(n == 0) return;
    cout << "["; 
    for(int i = 1; i<n; i++){
        cout << X[i] << " ";
    }
    cout << X[n] << "]" << endl;
    for(int k = 0; k<n; k++){
        X[k] = X[k] + X[k+1];
    }
    Try(n-1);  
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        init();
        Try(n);
    }
    return 0;
}