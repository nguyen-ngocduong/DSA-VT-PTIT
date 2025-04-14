#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<string> res;
        for(int i = s.size()-1; i>= 0; i--){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                string f1 = res.top();
                res.pop();
                string f2 = res.top();
                res.pop();
                string tmp = "(" + f1 + s[i] + f2 + ")";
                res.push(tmp);
            }
            else{
                res.push(string(1, s[i]));
            }
        }
        cout << res.top() << endl;
    }
    return 0;
}