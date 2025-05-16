#include<bits/stdc++.h>
using namespace std;
string s;
vector<pair<int,int>> daungoac; // luu  index cua dau ngoac
set<string> res;
void dfs(int idx, vector<bool> &remove){
    if(idx == daungoac.size()){
        string tmp; // lưu biểu thức sau khi xóa dấu ngoặc
        for(int i = 0; i<s.size(); i++){
            bool skip = 0;
            for(int j = 0; j<daungoac.size(); j++){
                if(remove[j] && (i == daungoac[j].first || i == daungoac[j].second)){
                    skip = 1;
                    break;
                }
            }
            if(!skip) tmp += s[i];
        }
        if(tmp != s) res.insert(tmp);
        return;
    }
    // không xóa cặp hiện tại
    remove[idx] = false;
    dfs(idx + 1, remove);
    // xóa cặp hiện tại
    remove[idx] = true;
    dfs(idx + 1, remove);
}
int main(){
    cin >> s;
    stack<int> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')'){
            int open = st.top();
            st.pop();
            daungoac.push_back({open,i});
        }
    }
    vector<bool> remove(daungoac.size(), false);
    dfs(0, remove);
    for(const string& str : res){
        cout << str << endl;
    }
    return 0;
}