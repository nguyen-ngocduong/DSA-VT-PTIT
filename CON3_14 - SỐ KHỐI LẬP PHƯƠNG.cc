#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void Init(){
    for(int i = 100; i>=1; i--){
        v.push_back(i*i*i);
    }
}
string solve(string &s){
    string tmp;
    for(int i = 0; i<v.size(); i++){
        tmp = to_string(v[i]);
        int id = 0;
        for(char c : s){
            if(c == tmp[id]){
                id++;
            }
        }
        if(id == tmp.size()){
            return tmp;
        }
    }
    return "-1";
}
int main(){
    int t; cin>>t;
    while(t--){
        Init();
        string s;
        cin>>s;
        cout << solve(s) << endl;
    }
    return 0;
}