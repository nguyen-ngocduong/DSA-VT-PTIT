#include<bits/stdc++.h>
using namespace std;
int ok;
int uutien(char c){
    if(c == '(') return 0;
    if(c == '*' || c == '/') return 3;
    if(c == '+' || c == '-') return 2;
    return 1;
}
int tinhtoan(int a, int b, char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/'){
        if(b!=0) return a/b;
        else return 0; 
    }
    return 0;
}
void solve(string s){
    stack<char> st1;
    stack<int> st2;
    for(int i = 0; i<s.size();i++){
        if(s[i] == '(') st1.push(s[i]);
        else if(isdigit(s[i])){
            int res = 0;
            while(i < s.size() && isdigit(s[i])){
                res = res*10 + s[i] - '0';
                i++;
            }
            st2.push(res);
            i--; // tranh tang do for
        }
        else if(s[i] == ')'){
            while(!st1.empty() && st1.top() != '('){
                char dau = st1.top(); st1.pop();
                int a = st2.top(); st2.pop();
                int b = st2.top(); st2.pop();
                st2.push(tinhtoan(b,a,dau));
            }
            st1.pop(); // pop '('
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            while(!st1.empty() && uutien(st1.top()) >= uutien(s[i])){
                char dau = st1.top(); st1.pop();
                int a = st2.top(); st2.pop();
                int b = st2.top(); st2.pop();
                st2.push(tinhtoan(b,a,dau));
            }
            st1.push(s[i]);
        }
    }
    while(!st1.empty() && st1.top() != '('){
        char dau = st1.top(); st1.pop();
        int a = st2.top(); st2.pop();
        int b = st2.top(); st2.pop();
        st2.push(tinhtoan(b,a,dau));
    }
    cout << st2.top() << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }
    return 0;
}