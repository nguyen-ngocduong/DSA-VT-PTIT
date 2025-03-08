#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<char, int> map;
        for(char x:s) map[x]++;
        int ans = 1;
        for(auto value : map){
            if(value.second > ceil(s.length()/2)){
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}