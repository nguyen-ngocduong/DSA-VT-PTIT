#include<bits/stdc++.h>
using namespace std;
int R,C;
int a[501][501];
//trái,trên, phải, dưới
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int BFS(){
    queue<pair<int, int>> q;
    int cntSeed = 0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(a[i][j] == 2) q.push({i,j});
            else if(a[i][j] == 1) cntSeed++;
        }
    }
    int days = 0;
    while(!q.empty()){
        bool datrong = 0;
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            pair<int, int> tmp = q.front();
            q.pop();
            for(int j = 0; j<4; j++){
                int newx = tmp.first + dx[j];
                int newy = tmp.second + dy[j];
                if(newx >= 0 && newx < R && newy >= 0 && newy < C && a[newx][newy] == 1){
                    a[newx][newy] = 2;
                    cntSeed--;
                    q.push({newx, newy});
                    datrong = 1;
                }
            }
        }
        if(datrong) days++;
    }
    if(cntSeed == 0) return days;
    else return -1;
}
int main(){
    int t; cin >> t;
    while (t--)
    {
        cin >> R >> C;
        for(int i = 0; i< R; i++)
            for(int j = 0; j< C; j++)
                cin >> a[i][j];
        cout << BFS() << endl;
    }
    return 0;
}