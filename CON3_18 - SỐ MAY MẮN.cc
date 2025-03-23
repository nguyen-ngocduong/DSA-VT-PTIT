#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int so4=0,so7=0;
        int check = 0;
        for(int i = n/7; i>=0; i--){
            if((n-(i*7))%4 == 0){
                so7 = i;
                so4 = (n-7*so7)/4;
                check = 1;
                break;
            }
        }
        if(check == 0){
            cout<<"-1"<<endl;
        }
        else{
            for(int i = 0; i<so4; i++){
                cout << "4";
            }
            for(int i = 0; i<so7; i++){
                cout << "7";
            }
        }
        cout << endl;
    }
    return 0;
}