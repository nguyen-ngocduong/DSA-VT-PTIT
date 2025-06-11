#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        pair<int, int> p[n];
        for(int i = 0; i<n; i++){
            p[i] = {a[i],b[i]};
        }
        sort(p,p+n,cmp);
        int end = p[0].second;
        int ans = 1;
        for(int i = 1; i<n; i++){
            if(p[i].first >= end){ // thời gian bắt đầu >= thời gian kết thúc của hoạt động trước
                ans++;
                end = p[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}