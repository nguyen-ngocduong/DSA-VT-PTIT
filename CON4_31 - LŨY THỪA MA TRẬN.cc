#include<bits/stdc++.h>
#define MODE 1000000007
using namespace std;
int n,k;
struct Matran {
    long long f[100][100];
};
Matran operator*(Matran a, Matran b){
    Matran res;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            res.f[i][j] = 0;
            for(int k = 0; k<n; k++){
                res.f[i][j] += (a.f[i][k] * b.f[k][j])%MODE;
                res.f[i][j] %= MODE;
            }
        }
    }
    return res;
}
Matran bin_pow(Matran a, int b){
    if(b == 1) return a;
    Matran tmp = bin_pow(a, b/2);
    if(b%2 == 1) return tmp*tmp*a;
    return tmp*tmp;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        Matran a;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n;j++){
                cin >> a.f[i][j];
            }
        }
        Matran b = bin_pow(a,k);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << b.f[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}