#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
    int n; cin >> n;
    for(int i = 1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        a[i][x] = a[i][y] = 1;
    }
    for(int i = 1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cout<< a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}