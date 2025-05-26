#include<bits/stdc++.h>
using namespace std;
int n,k,ok;
vector<string> ans;
char a[1005];
void init(){
    cin >> n >> k;
    ans.clear();
    memset(a,'A', sizeof(a));
    ok = 1;
}
void next(){
    int i = n;
    while(i > 0 && a[i] == 'B'){
        a[i] = 'A';
        i--;
    }
    if(i == 0){
        ok = 0;
    }
    else a[i] = 'B';
}
bool check(){
    int res = 0, cauhinh = 0;
    for(int i = 1; i<= n; i++){
        if(a[i] == 'A'){
            res++;
            if(res == k) cauhinh++;
            if(res>k) return 0;
        }
        else res = 0;
    }
    return cauhinh == 1;
}
int main(){
    init();
    while(ok){
        if(check()){
            string s = "";
            for(int i = 1; i<=n; i++){
                s += a[i];
                s += " ";
            }
            ans.push_back(s);
        }
        next();
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        for(char c : x){
            cout << c;
        }
        cout << endl;
    }
    return 0;
}