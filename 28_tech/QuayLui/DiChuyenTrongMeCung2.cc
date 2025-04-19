#include <bits/stdc++.h>
using namespace std;

int n, a[1001][1001], ok;
string s;

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

/* void Try(int i, int j){
    if(i == n && j == n){
        ok = 1;
        cout << s << " ";
        return;
    }

    // Down
    if(i+1 <= n && a[i+1][j]){
        s += "D";
        a[i+1][j] = 0;
        Try(i+1, j);
        a[i+1][j] = 1;
        s.pop_back();
    }

    // Left
    if(j-1 >= 1 && a[i][j-1]){
        s += "L";
        a[i][j-1] = 0;
        Try(i, j-1);
        a[i][j-1] = 1;
        s.pop_back();
    }

    // Right
    if(j+1 <= n && a[i][j+1]){
        s += "R";
        a[i][j+1] = 0;
        Try(i, j+1);
        a[i][j+1] = 1;
        s.pop_back();
    }

    // Up
    if(i-1 >= 1 && a[i-1][j]){
        s += "U";
        a[i-1][j] = 0;
        Try(i-1, j);
        a[i-1][j] = 1;
        s.pop_back();
    }
} */

//Cach 2
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
string path = "DLRU";
void Try(int i, int j){
    if (i == n && j == n){
        ok = 1;
        cout << s << " ";
    }
    for (int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]){
            s += path[k];
            a[i1][j1] = 0;
            Try(i1,j1);
            a[i1][j1] = 1;
            s.pop_back();
        }
    }
}
void solve(){
    init();
    ok = 0;
    s = "";
    if(a[1][1] && a[n][n]){
        a[1][1] = 0; // đánh dấu đã đi
        Try(1, 1);
    }
    if(!ok) cout << -1 << endl;
    else cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}