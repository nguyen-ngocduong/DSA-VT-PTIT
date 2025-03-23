#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--){
        int P,Q; cin >> P >> Q;
        int a[P+1], b[Q+1], c[P+Q+1] = {};
        for(int i = P; i>=1; i--){
            cin >> a[i];
        }
        for(int j = Q; j>=1; j--){
            cin >>b[j];
        }
        for(int i = 1; i<=P; i++) 
            for(int j = 1; j<= Q; j++)
                c[i+j] += a[i]*b[j];
        for(int i = P+Q; i>=2; i--) cout << c[i] << " ";
        cout << endl;
    }
    return 0;
}