#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001][1001], n;
void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    s = "";
}
void Try(int i, int j){
    if(i == n-1 && j == n-1){
        cout << s << " ";
        return;
    } 
    if(i + 1 <= n && a[i+1][j] == 1 ){
        s += "D";
        a[i+1][j] = 1;
        Try(i+1,j);
        s.pop_back();
        a[i+1][j] = 0;
    }
    if(j + 1 <= n && a[i][j+1] == 1){
        s += "R";
        a[i][j+1] = 1;
        Try(i,j+1);
        s.pop_back();
        a[i][j+1] = 0;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        if (a[0][0] == 1) {
            Try(0, 0);
        }
        cout << endl;
    }
    return 0;
}