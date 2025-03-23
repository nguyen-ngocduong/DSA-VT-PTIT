#include<bits/stdc++.h>
using namespace std;
int main () {
    int t; cin >> t;
    while(t--) {
        int d; string s;
        cin >> d >> s;
        map<char, int> mp;
        for (char key : s) mp[key]++;
        int max_fre = 0;
        for(auto value : mp){
            max_fre = max(max_fre, value.second);
        }
        int len = s.size();
        if(max_fre < len /(d-1)){
            cout << "1" << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}