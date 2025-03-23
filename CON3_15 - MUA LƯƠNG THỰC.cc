#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >>t;
    while (t --)
    {
        int n,s,m;
        cin >> n >> s >> m;
        if(6*n < 7*m && s > 6 || m > n){
            cout << -1 << endl;
        }
        else {
            int res = (m*s)/n;
            if((m*s)%n != 0) res ++;
            cout << res << endl;
        }
    }
    return 0;
}