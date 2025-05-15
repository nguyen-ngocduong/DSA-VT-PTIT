#include <bits/stdc++.h>
using namespace std;

/*int main(){
    int n; cin >> n;
    int a[n]; 
    for(int i = 0; i<n; i++){
        cin >> a[n];
    }
    cout << "1 1 2 1 5 1 7 1 2 1" << endl;
    return 0;
}*/
int main(){
    int n; cin >> n;
    int a[n];
    vector<int> span(n); 
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    stack<int> st;
    for(int i = 0; i<n; i++){
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
    
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }
    
        st.push(i);
    }
    for(int x : span){
        cout << x " ";
    }
    cout << endl;
    return 0;
}
