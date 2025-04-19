#include<bits/stdc++.h>
using namespace std;
int n, X[105], c[105][105],visited[105];
int cost = 0, cmin = INT_MAX, toiuu = INT_MAX;
void init(){
    memset(visited, 0, sizeof(visited));
    cin >> n;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            cin >> c[i][j];
            if(c[i][j]) {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}
void Try(int i){
    for(int j = 2; j<= n; j++){
        if(!visited[j]){
            visited[j] = 1;
            X[i] = j; // thanh pho di tiep duoc lua chon la j
            cost += c[X[i]][X[i-1]];
            if(i == n){
                toiuu = min(toiuu, cost + c[X[n]][1]);
            }
            else if(cost + (n-i+1) * cmin <= toiuu){
                Try(i+1);
            }
            visited[j] = 0;
            cost -= c[X[i]][X[i-1]];
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        X[1] = 1;
        Try(2);
        cout << toiuu << endl;
    }
    return 0;
}