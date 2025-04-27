#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> canh;
        vector<int> ke[1001];
        int a[n+1][n+1]; // n+1 vì mảng 1-indexed

        for(int i = 0; i < 1001; i++) ke[i].clear();

        // Nhập ma trận kề
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }

        // Xử lý từ ma trận kề
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] == 1){
                    ke[i].push_back(j);
                    canh.push_back({i, j});
                }
            }
        }

        // In danh sách cạnh
        for(auto value : canh){
            cout << value.first << " " << value.second << endl;
        }
        cout << endl;
        // In danh sách kề
        for(int i = 1; i <= n; i++){
            cout << i << ": ";
            for(int x : ke[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
