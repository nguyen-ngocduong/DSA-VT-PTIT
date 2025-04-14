#include<bits/stdc++.h>
using namespace std;
long long n, a[101];
void init(){
    a[0] = a[1] = 1;
    for(int i = 1; i<= 101; i++){
        for(int j = 0; j <= i; j++){
            a[i+1] += a[j] * a[i - j];
        }
    }
}
int main(){
    int t; cin >> t;
    init();
    while (t--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}