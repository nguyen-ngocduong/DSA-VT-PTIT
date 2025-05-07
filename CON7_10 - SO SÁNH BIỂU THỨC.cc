#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        stack<char> st;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] == '(' && (s1[i-1] == '-' || s1[i-1] == '+')) st.push(s1[i-1]);
            if(!st.empty() && st.top() == '-'){
                if(s1[i] == '-') s1[i] = '+';
                else if(s1[i] == '+') s1[i] = '-';
            }
            if(!st.empty() && s1[i] == ')') st.pop();
        }
        string res = "";
        for(char &c:s1){
            if(c != '(' && c != ')') res += c;
        }
        if(res == s2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}