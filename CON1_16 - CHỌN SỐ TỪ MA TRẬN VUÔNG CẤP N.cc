#include<bits/stdc++.h>
using namespace std;
int a[1005], dp[105][105];
int main(){
    int t; t = 1;
    while(t--){
        int n,k; cin >> n >> k;
        for(int i = 1; i<= n; i++) {
            for(int j = 1; j<= n; j++){
                cin >> dp[i][j];
            }
        }
        for(int i = 1; i<=n ;i++) {
            a[i] = i;
        }
        vector<vector<int>> v; //lưu cấu hình + số lượng ptu
        //sử dụng next_permutation()
        do{
            int sum = 0;
            for(int i = 1; i<=n; i++){
                sum += dp[i][a[i]];
            }
            if(sum == k) {
                vector<int> tmp(a+1, a+n+1);
                v.push_back(tmp);
            }
        }while(next_permutation(a+1, a + n + 1));
        cout << v.size() << endl;
        for(vector<int> value : v){
            for(int x : value){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}