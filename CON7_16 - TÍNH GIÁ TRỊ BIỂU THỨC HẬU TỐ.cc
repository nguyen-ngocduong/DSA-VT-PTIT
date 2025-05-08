#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(int i = 0;i <s.size(); i++){
            if(s[i] == '+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(s[i] == '+') st.push(a+b);
                if(s[i] == '-') st.push(b-a);
                if(s[i] == '*') st.push(a*b);
                if(s[i] == '/') st.push(b/a);
            }
            else {
                st.push(s[i] - '0');
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}