#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> v;
    cin.ignore();
    for(int i = 1; i<=n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        while(ss >> x){
            if(x > i) v.push_back({i,x});
        }
    }
    for(auto value : v){
        cout << value.first << " " << value.second << endl;
    }
    return 0;
}