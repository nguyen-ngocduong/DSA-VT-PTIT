#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string a,b; cin >> a >> b;
        string res = "";
        while(a.size() < b.size()) a = "0" + a;
        while(a.size() > b.size()) b = "0" + b;
        int nho = 0;
        for(int i = a.size() - 1; i>=0; i--){
            int num = (a[i] - '0') + (b[i] - '0') + nho;
            res += to_string(num % k);
            nho = num / k;
        }
        if(nho) res += to_string(nho);
        reverse(begin(res), end(res));
        cout << res << endl;
    }
    return 0;
}