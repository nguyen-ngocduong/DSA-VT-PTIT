#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int MIN = 1e9;
        int ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int x = a[i] + a[j] - 0;
                if(abs(x) < MIN)
                {
                    MIN = abs(x);
                    ans = x;
                }
            }
        }
        cout << ans << endl;
    }
}