#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    int n;
    while(t--) {
        cin >> n;
        string s; cin >> s;
        map<char, int> mp;
        for(char key : s) mp[key]++;
        vector<int> v;
        for(auto value : mp){
            v.push_back(value.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        while(n--){
            v[0] -= 1;
            sort(v.begin(), v.end(), greater<int>());
        }
        long long res = 0;
        for(int x : v){
            res += x*x;
        }
        cout << res << endl;
    }
    return 0;
}