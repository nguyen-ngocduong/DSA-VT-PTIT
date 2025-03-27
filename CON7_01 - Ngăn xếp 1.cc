#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int value;
    stack<int> st;
    
    while (cin >> s) {
        if (s == "push") {
            cin >> value;
            st.push(value);
        }
        
        if (s == "show") {
            if (st.empty()) {
                cout << "empty" << endl;
            } else {
                stack<int> temp;
                while (!st.empty()) {
                    temp.push(st.top());
                    st.pop();
                }
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    st.push(temp.top());
                    temp.pop();
                }
                cout << endl;
            }
        }
        
        if (s == "pop" && !st.empty()) {
            st.pop();
        }
    }
    
    return 0;
}
