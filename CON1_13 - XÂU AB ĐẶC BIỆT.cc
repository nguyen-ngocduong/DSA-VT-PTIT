#include<bits/stdc++.h>
using namespace std;
int n,k,ok,a[105];
vector<string>ans;
void init(){
    cin>>n>>k;
    ans.clear();
    memset(a,0,sizeof(a));
    ok=1;
}
void res(){
    string s="";
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            s+="A ";
        }
        else{
            s+="B ";
        }
    }
    ans.push_back(s);
}
void sinh(){
    int i=n;
    while(i>0&&a[i]==1){
        a[i]=0;
        i--;
    }
    if(i<=0){
        ok=0;
    }
    else{
        a[i]=1;
    }
}
bool check(){
    int d=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            d++;
            if(d>k){
                return 0;
            }
            if(d==k){
                cnt++;
            }
        }
        else{
            d=0;
        }
    }
    return cnt==1;
}
int main(){
    init();
    while(ok){
        if(check()){
            res();
        }
        sinh();
    }
    cout<<ans.size()<<"\n";
    for(string x:ans){
        cout<<x<<"\n";
    }
    return 0;
}