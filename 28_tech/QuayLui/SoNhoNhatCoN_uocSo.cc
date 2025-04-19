#include<bits/stdc++.h>
using namespace std;
int t, n;
long long p[10] = {2,3,5,7,9,11,13,17,19,23,29};
long long Try(int pos, int count, int x){
    if(cnt == n) return x;
    int i = 1;
    long long temp = LLONG_MAX;
    while(true){
        x *= p[pos];
        if(x > temp) break;
        if(cnt*(i+1) > n) break;
        temp = min(temp, Try(pos + 1, count * (i+1), x))
        i++;
    }
    return temp;
}
void solve(){
    cin >> t;
    while(t--){
        cin >> n;
        long long res = Try(0,1,1);
        cout << res << endl;
    }
}
int main(){
    solve();
    return 0;
}