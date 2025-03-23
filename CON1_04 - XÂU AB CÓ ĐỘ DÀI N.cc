#include<bits/stdc++.h>
using namespace std;
int n, a[1005], ok;
void next(){
    int i = n;
    while(i > 0 && a[i] == '1'){
        a[i] = '0';
        i--;
    }
    if(i == 0){
        ok = 0;
    }
    else {
        a[i] = '1';
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        memset(a, 0, sizeof(a));
        ok = 1;
        while(ok){
            for(int i = 1; i<=n; i++){
                if(a[i] == '1') cout << 'B';
                else cout << 'A';
            }
            cout << ' ';
            next();
        }
        cout << endl;
    }
    return 0;
}