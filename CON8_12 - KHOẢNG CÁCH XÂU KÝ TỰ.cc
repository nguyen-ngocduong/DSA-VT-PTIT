#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s,t;
        cin >> s >> t;
        map<string, int> mp; //Dùng để lưu tập từ điển S.
        map<string, int> check;//Dùng để đánh dấu những từ đã duyệt qua trong BFS.
        queue<pair<string, int>> q;
        for(int i = 0; i<n; i++){
            string word; cin >> word;
            mp[word]++;
        }
        q.push({s, 1});
        while(!q.empty()){
            string xau = q.front().first;
            int step = q.front().second;
            q.pop();
            if(xau == t){
                cout << step << endl;
                break;
            }
            for(int i = 0;i<xau.size(); i++){
                string newXau = xau;
                for(char x = 'A'; x <= 'Z'; x++){
                    newXau[i] = x;
                    if(newXau == xau || check[newXau] || !mp[newXau]) continue;
                    check[newXau] = 1;
                    q.push({newXau, step + 1});
                }
            }
        }
    }
    return 0;
}