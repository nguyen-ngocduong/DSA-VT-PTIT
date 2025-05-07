#include<bits/stdc++.h>
using namespace std;
/*Trường hợp 1: dấu đóng ngoặc nhưng đỉnh là mở ngoặc => không có các toán tử ở giữa nên sai
Trường hợp 2: có dấu đóng ngoặc như ko có mở ngoặc => sai
Trường hợp 3: có dấu đóng ngoặc có dấu mở ngoặc có toán tử ở giữa thì pop mở ngoặc khỏi stack*/
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> st;
        bool ok;
        for(int i = 0; i<s.size(); i++){
            if(s[i] != ')') st.push(s[i]);
            else{
                ok = true;
                char top = st.top();
                st.pop();
                while(top != '('){
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        ok = false;
                    }
                    top = st.top();
                    st.pop();
                }
                if(ok) break;
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}