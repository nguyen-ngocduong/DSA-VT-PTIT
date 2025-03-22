#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string s="0000000000009";
vector<string>v;
vector<ll>ans;
int n=13,ok=1;
void sinh(){
    int i=n-1;
    while(i>=0&&s[i]=='9'){
        s[i]='0';
        i--;
    }
    if(i<0){
        ok=0;
    }
    else{
        s[i]='9';
    }
}
void preCal(){
  
    while(ok){
        v.push_back(s);
        sinh();
    }
    for(int i=1;i<=500;i++){
        for(string x:v){
            ll tmp=stoll(x);
            if(tmp%i==0){
                ans.push_back(tmp);
                break;
            }
        }
    }
}
int main()
{    
    preCal();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<ans[n-1]<<"\n";
    }
    return 0;
}