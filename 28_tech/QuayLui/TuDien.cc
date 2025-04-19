#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int k,m,n;
set<string> dict;
string s;
int visited[100][100];
vector<string> res;
void init(){
    cin >> k >> n >> m;
    for(int i = 0; i<k; i++){
        string words; 
        cin >> words;
        dict.insert(words);
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    memset(visited,0,sizeof(visited));
}
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
void Try(int i, int j){
    s += a[i][j];
    if(dict.count(s)) res.push_back(s);
    for(int k = 0; k < 8; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && visited[i1][j1]==0){
            visited[i1][j1] = 1;
            Try(i1,j1);
            visited[i1][j1] = 0;
        }
    }
    s.pop_back();
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                Try(i,j);
            }
        }
        sort(res.begin(), res.end());
        for(string x : res){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}