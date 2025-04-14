#include<bits/stdc++.h>
using namespace std;
int biendoi(string &s){
    long long tmp = 1;
    long long res = 0;
    for(int i = s.size() - 1; i>= 0; i--){
        res += tmp * (s[i] - '0');
        tmp *= 2;
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        long long x = biendoi(a), y = biendoi(b);
        cout << x * y << endl;
    }
    return 0;
}