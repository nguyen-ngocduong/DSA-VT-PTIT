#include<bits/stdc++.h>
using namespace std;
int main (){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int &x : v){
            cin >> x;
        }
        sort(v.begin(), v.end());
        long long sum1 = 0, sum2 = 0;
        for(int i = 0; i< n; i++) {
            if(i%2 == 0) sum1 = sum1 * 10 + v[i];
            else sum2 = sum2 * 10 + v[i];
        }
        cout << (sum1+sum2) << endl;
    }
    return 0;
}