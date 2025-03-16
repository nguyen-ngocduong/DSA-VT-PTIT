#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i<n; i++) cin >> a[i];
        int MAX = -100;
        int i = 0;
        while (i < n)
        {
            int cnt1 = 0, cnt2 = 0;
            for(int j = i+1; j<n; j++) {
                if(a[j] < a[i]) break;
                else cnt1++;
            }
            for(int j = i-1; j>=0; j--){
                if(a[j] < a[i]) break;
                else cnt2++;
            }
            MAX = max(MAX, a[i] * (cnt1 + cnt2 + 1));
            i++;
        }
        cout << MAX << endl;
    }
    return 0;
}