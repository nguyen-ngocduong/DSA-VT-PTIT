#include<bits/stdc++.h>
using namespace std;
struct job{
    int id,dl,pro;
    bool operator<(job o){
        return pro > o.pro;
    }
};
int main () {
    int t; cin >>t;
    while(t--){
        int n; cin >>n;
        job a[n];
        for(int i = 0; i<n; i++) cin >> a[i].id >> a[i].dl >> a[i].pro;
        sort(a,a+n);
        int ans = 0, value = 0;
        vector<int> busy(1001, 0);
        for(int i = 0; i<n;i++){
            for(int j = a[i].dl; j>=1; j--){
                if(!busy[j]){
                    ans++;
                    value += a[i].pro;
                    busy[j] = 1;
                    break;
                }
            }
        }
        cout << ans << " " << value << endl;
    }
    return 0;
}