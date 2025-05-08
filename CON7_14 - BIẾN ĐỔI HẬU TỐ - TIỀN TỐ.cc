#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<string> st;
        // Thay đổi 1: Duyệt từ TRÁI SANG PHẢI (0 -> s.size()-1)
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
                string f1 = st.top();
                st.pop();
                string f2 = st.top();
                st.pop();
                string ans = s[i] + f2 + f1;
                st.push(ans);
            }
            else st.push(string(1,s[i]));
        }
        cout << st.top() << endl;
    }
    return 0;
}