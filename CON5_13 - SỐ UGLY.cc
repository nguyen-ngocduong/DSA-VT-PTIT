#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long ugly[n+1];
        ugly[0] = 1;
        int i2 = 0, i3=0, i5=0;
        for(int i = 1; i<n; i++){
            ugly[i] = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
            if(ugly[i] == ugly[i2] * 2) i2++;
            if(ugly[i] == ugly[i3] * 3) i3++;
            if(ugly[i] == ugly[i5] * 5) i5++;
        }
        cout << ugly[n-1] << endl;
    }
    return 0;
}