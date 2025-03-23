#include<bits/stdc++.h>  
using namespace std;

int a[20][20], n, res = INT_MAX; 
bool dd[20] = {}; // Mảng đánh dấu các thành phố đã thăm

void Try(int i, int sum = 0, int cnt = 1) {
    if(sum > res) return; 
    if(cnt == n) { 
        res = min(res, sum + a[i][1]); 
        return;
    }
    for(int j = 1; j <= n; ++j) {
        if(!dd[j]) { 
            dd[j] = 1; 
            Try(j, sum + a[i][j], cnt + 1); 
            dd[j] = 0;
        }
    }
}

int main() {
    cin >> n; 
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) cin >> a[i][j]; 
    dd[1] = 1; 
    Try(1); 
    cout << res; 
    return 0;
}