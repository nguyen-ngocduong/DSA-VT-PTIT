#include<bits/stdc++.h>
using namespace std;

int gtmax(vector<int> a,int n){
    int mx = -1e6-7;
    for(int i=0;i<n;i++){
        int sum=a[i];
        for(int j=i+1;j<n;j++){
            sum+=a[j];
            mx=max(mx,sum);
        }
    }
    return mx;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &x: a) cin>>x;
        cout<<gtmax(a,n)<<endl;
    }
    return 0;
}