#include<bits/stdc++.h>
using namespace std;
int n,a[100],X[100];
vector<string> ans;
void init(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    //sort(a+1,a+n+1);
    ans.clear();
}
void Try(int i, int pos){ //pos vi tri de quay lui
    for(int j = pos; j<=n; j++){
        if(X[i-1] < a[j]){
            X[i] = a[j];
            if(i>1){
                string res = "";
                for(int j = 1;j<=i;j++){
                    res += to_string(X[j]) + " ";
                }
                ans.push_back(res);
            }
            Try(i+1,j+1);
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        Try(1,1);
        sort(begin(ans), end(ans));
        for(string x : ans){
            cout << x << endl;
        }
    }
    return 0;
}