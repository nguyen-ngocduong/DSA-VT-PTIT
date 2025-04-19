#include<bits/stdc++.h>
using namespace std;
int Try(int n){
    int x = 1e9, y = 1e9, z = 1e9;
    if(n == 1) return 0;
    if(n % 2 == 0){
        x = 1 + Try(n/2);
    }
    if(n%3==0){
        y=1+Try(n/3);
    }
    if(n>1) z = 1 + Try(n-1);
    return min({x,y,z});
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << Try(n) << endl;
    }
    return 0;
}