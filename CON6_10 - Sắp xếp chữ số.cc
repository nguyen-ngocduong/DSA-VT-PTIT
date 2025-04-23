#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >>  t;
    while(t--){
        int n; cin >> n;
        map<char, char> mp;
        string res = "";
        for(int i = 0; i<n; i++){
            string num;
            cin >> num;
            res += num;
        }
        for(int i = 0; i<res.size();i++){
            mp[res[i]]++;
        }
        for(const auto value : mp){
            cout << value.first << " ";
        }
        cout << endl;
    }
    return 0;
}
