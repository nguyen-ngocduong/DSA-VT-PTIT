#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> res;
        cin.ignore();
        for(int i = 1; i<=n; i++){
            string s,num;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> num){
                res.push_back({i,stoi(num)});
            }
        }
        sort(begin(res),end(res));
        for(auto value : res){
            cout << value.first << " " << value.second << endl;
        }
    }
    return 0;
}