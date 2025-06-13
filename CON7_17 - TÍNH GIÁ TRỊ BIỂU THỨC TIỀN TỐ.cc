#include<bits/stdc++.h>
using namespace std;
bool dau(char c){
    return c == '+' || c == '-' || c == '*' || c== '/';
}
int calculate(int a, int b, char op){
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if(b == 0) {
            return 0;
        }
        return a/b;
    default:
        return 0;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(int i = s.size()-1; i>=0; i--){
            if(dau(s[i])){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = calculate(a,b,s[i]);
                st.push(res);
            }
            else st.push(s[i] - '0');
        }
        cout << st.top() << endl;
    }
    return 0;
}