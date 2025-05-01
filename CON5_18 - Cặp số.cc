#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            int x,y;
            cin >> x >> y;
            v[i] = {x,y};
        }
        sort(begin(v), end(v), cmp);
        vector<int> dp(n+1, 1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(v[i].first > v[j].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(begin(dp), end(dp)) << endl;
    }
    return 0;
}