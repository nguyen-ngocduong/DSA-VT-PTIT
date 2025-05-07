#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> stk;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == '(' && (s[i-1]=='-'||s[i-1]=='+')) stk.push(s[i-1]);
			if(!stk.empty() && stk.top() == '-')
			{
				if(s[i] == '-') s[i] = '+';
				else if(s[i] == '+') s[i] = '-';
			}
			if(!stk.empty()&& s[i]==')') stk.pop();
		}
        string res = "";
        for(char &c : s){
            if(c != '(' && c != ')') res += c;
        }
        cout << res << endl;
    }
    return 0;
}