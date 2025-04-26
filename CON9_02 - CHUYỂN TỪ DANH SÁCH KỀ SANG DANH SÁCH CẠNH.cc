#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    vector<pair<int,int>> res;
    cin.ignore();
    for(int i = 1; i<=n; i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int x;
        while(ss >> x){
            if(x > i) res.push_back({i, x});
        }
    }
    for(auto value : res){
        cout << value.first << " " << value.second << endl;
    }
    return 0;
}