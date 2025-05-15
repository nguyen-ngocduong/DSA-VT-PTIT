#include<bits/stdc++.h>
using namespace std;
int BFS(int n){
    queue<pair<int, int>> q;
    q.push({n,0});
    map<int, int> daxet;
    daxet[n] = 1;
    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp.first == 1){
            return tmp.second;
        }
        for(int i = 2; i <= sqrt(tmp.first); i++){
            if(tmp.first % i == 0){
                int m = max(i, tmp.first / i);
                if(daxet[m] == 0){
                    q.push({m, tmp.second + 1});
                    daxet[m] = 1;
                }
            }
        }
        if(daxet[tmp.first - 1] == 0) {
            q.push({tmp.first - 1, tmp.second + 1});
            daxet[tmp.first - 1] = 1;
        }
    }
    return 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << BFS(n) << endl;
    }
    return 0;
}