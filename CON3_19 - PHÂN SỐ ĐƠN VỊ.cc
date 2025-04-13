#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        long long tu, mau; cin >> tu >> mau;
        while(true){
            if(mau%tu == 0){
                cout << "1/" << mau/tu;
                break;
            }
            else {
                long long tmp = mau/tu+1;
                cout << "1/" << tmp << " + ";
                tu = tmp * tu - mau;
                mau = tmp * mau;
            }
        }
        cout << endl;
    }
    return 0;
}