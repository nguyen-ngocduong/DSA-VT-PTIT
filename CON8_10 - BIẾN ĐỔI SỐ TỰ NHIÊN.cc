#include<bits/stdc++.h>
#define	fi first
#define se second
using namespace std;
int BFS(int n){
    queue<pair<int, int>> q;
    q.push({n, 0}); // cap so xet va thao tac
    map<int, int> daxet;
    daxet[n] = 1;
    while(q.size()){
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp.fi == 1){
            return tmp.se;
        }
        // tim uoc 
        for(int i = 2; i<= sqrt(tmp.fi); i++){
            if(tmp.fi % i == 0){
                int m = max(i, tmp.fi / i);
                if(daxet[m] == 0){
                    q.push({m, tmp.se + 1});
                    daxet[m] = 1;
                }
            }
        }
        if(daxet[tmp.fi - 1] == 0){
            q.push({tmp.fi - 1, tmp.se + 1});
            daxet[tmp.fi - 1] = 1;
        }
    }
    return 0;
}
int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << BFS(n) << endl;
    }
    return 0;
}