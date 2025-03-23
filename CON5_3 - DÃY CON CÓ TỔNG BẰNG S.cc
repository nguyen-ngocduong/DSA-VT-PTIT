#include<bits/stdc++.h>
using namespace std;
#define maxn 201
#define MAX 40001
int main(){
    int t; cin>>t;
    while(t--) {
        int n,s; cin>>n>>s;
        int a[maxn];
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        bool c[MAX];
        memset(c,0,sizeof(c));
        for(int i = 1; i<=n; i++){
            c[a[i]] = true;
            for(int j = s; j>=0; j--)
                if(j >= a[i] && c[j-a[i]])
                    c[j] = true;
        }
        if(c[s] == true) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    return 0;
}