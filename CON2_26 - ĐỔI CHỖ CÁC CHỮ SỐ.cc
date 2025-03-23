#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        string s; cin >> s;
        for(int i = 0; i<s.size() && k>0; i++){
            int max_id = i;
            for(int j = i+1; j<s.size(); j++){
                if(s[max_id] <= s[j]) max_id = j;
            }
            if(max_id != i){
                swap(s[max_id], s[i]);
                k--;
            }
        }
        cout << s << endl;
    }
    return 0;
}