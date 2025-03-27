#include<bits/stdc++.h>
using namespace std; 
int max_profit(vector<int> &v){
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;
    for(int price : v){
        buy1 = min(buy1, price);
        profit1 = max(profit1, price - buy1);
        buy2 = min(buy2, price - profit1);
        profit2 = max(profit2, price - buy2);
    }
    return profit2;
}
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        cout << max_profit(v) << endl;
    }
    return 0;
}