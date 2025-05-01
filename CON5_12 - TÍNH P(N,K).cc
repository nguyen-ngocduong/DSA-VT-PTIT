#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int t; 
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        long long ans = 1;
        if(k > n)
        {
            ans = 0;
        }
        else 
        {
            for(int i = 1; i<=k; i++)
            {
                ans = ans*(n-i+1);
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}