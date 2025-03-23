#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005], ok;
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
    int cnt = 0, res = 0;
    for(int i = 1; i<= n; i++){
        if(a[i] == 0) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        if(cnt > k) return false;
        if(cnt == k) res++;
    }
    return res == 1;
}
int main(){
    int t; t = 1;
    while(t--) {
        cin >> n >> k;
        memset(a,0,sizeof(a));
        ok =1;
        while(ok){
            if(check()){
                for(int i = 1; i<=n; i++){
                    if(a[i] == 0) cout << "A";
                    else cout << "B";
                }
                cout << endl;
            }
            next();
        }
    }
    return 0;
}