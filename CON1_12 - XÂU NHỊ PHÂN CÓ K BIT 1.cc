#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],ok;
void next(){
    int i = n;
    while(i > 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0){
        ok = 0;
    }
    else a[i] = 1;
}

bool check(){
    int res = 0;
    for(int i = 1; i<=n; i++) {
        res += a[i];
    }
    return res == k;
}

int main() {
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        memset(a,0,sizeof(a));
        ok = 1;
        while(ok){
            if(check()) {
                for(int i = 1; i<= n; i++) cout << a[i];
                cout << endl;
            }
            next();
        }
    }
    return 0;
}