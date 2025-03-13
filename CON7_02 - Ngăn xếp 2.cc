#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main () {
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        int x;
        if(s == "PUSH") {
            cin >> x;
            st.push(x);
        }
        else if(s == "POP" && st.size() != 0){
            st.pop();
        }
        else if(s == "PRINT") {
            if(st.size() == 0){
                cout << "NONE" << endl;
            }
            else {
                cout << st.top() << endl;
            }
        }
    }
    return 0;
}