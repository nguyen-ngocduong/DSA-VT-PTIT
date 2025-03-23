#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int cost = 0, count = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '[') count ++;
            else count--;
            if(count < 0) {
                for(int j = i+1; j< s.size(); j++){
                    if(s[j] == '['){
                        cost += j - i;
                        swap(s[i], s[j]);
                        count = 1;
                        break;
                    }
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}