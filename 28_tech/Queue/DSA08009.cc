#include<bits/stdc++.h>
using namespace std;
int dem(int s, int t){
    if(s >= t) return s-t;
    else if(t%2==0){
        return 1+dem(s,t/2);
    }
    else{
        return 1+dem(s,t+1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int s,t; cin >> s >> t;
        cout << dem(s,t) << endl;
    }
    return 0;
}