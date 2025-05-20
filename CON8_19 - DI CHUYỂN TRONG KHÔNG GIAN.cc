#include<bits/stdc++.h>
using namespace std; 
struct  Node
{
    int z, x, y; //cao,dai, rong
};
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {0,0,0,0,1,-1};
int dz[6] = {1,-1,0,0,0,0};
int main(){
    int t; cin >> t;
    while(t--){
        int A,B,C; cin >> A >> B >>C;
        vector<vector<string>> grid(A, vector<string>(B));
        Node S,E;
        for(int z = 0; z<A; z++){
            for(int x = 0; x < B; x++){
                cin >> grid[z][x];
                for(int y = 0; y < C; y++){
                    if (grid[z][x][y] == 'S') S = {z, x, y};
                    if (grid[z][x][y] == 'E') E = {z, x, y};
                }
            }
        }
        vector<vector<vector<int>>> dist(A, vector<vector<int>>(B, vector<int>(C, -1)));
        queue<Node> q;
        dist[S.z][S.x][S.y] = 0;
        q.push(S);
        while(!q.empty()){
            Node current = q.front();
            q.pop();
            for(int k = 0; k<6; k++){
                int newz = current.z + dz[k];
                int newx = current.x + dx[k];
                int newy = current.y + dy[k];
                if (newz < 0 || newz >= A || newx < 0 || newx >= B || newy < 0 || newy >= C)
                    continue;
                if (grid[newz][newx][newy] == '#' || dist[newz][newx][newy] != -1)
                    continue;
                dist[newz][newx][newy] = dist[current.z][current.x][current.y] + 1;
                q.push({newz, newx, newy});
            }
        }
        cout << dist[E.z][E.x][E.y] << endl;
    }
    return 0;
}