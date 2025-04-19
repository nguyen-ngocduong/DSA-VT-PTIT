#include<bits/stdc++.h>
using namespace std;
int cot[100], d1[100], d2[100],n;
int X[100]; //mang luu cau hinh
int cnt;
void init(){
    memset(cot, 0, sizeof(cot));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
}
void Try(int i){
    //Dat cho
    for(int j = 1; j<=n; j++){
        if(cot[j] == 0 && d1[i - j + n] == 0 && d2[i+j-1] == 0){
            X[i]  = j;
            cot[j] = 1;
            d1[i-j+n] = 1;
            d2[i+j-1] = 1;
            if(i == n){
                for(int k = 1; k <= n; k++){
                    cout << "Con hau thu "<< k << " nam o vi tri " << X[k] << " !"<< endl;
                }
                cnt++;
                cout << endl;
            }
            Try(i+1);
            cot[j] = 0;
            d1[i-j+n] = 0;
            d2[i+j-1] = 0;
        }
    }
}
int main(){
    init();
    cin >> n;
    Try(1);
    cout << cnt << endl;
}