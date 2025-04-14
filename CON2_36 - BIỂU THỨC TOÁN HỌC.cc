#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a[10], b[10], c[10];
        string ans = "NO";
        for(int i = 1; i <= 5; i++)
        {
            cin >> a[i];
            b[i] = i;
        }
        do
        {
            c[1] = c[2] = c[3] = c[4] = 1;
            while(1)
            {
                int x = a[b[1]];
                int ok = 0;
                for(int i = 1; i <= 4; i++)
                {
                    if(c[i] == 1)
                    {
                        x = x + a[b[i + 1]];
                    }
                    else if(c[i] == 2)
                    {
                        x = x - a[b[i + 1]];
                    }
                    else
                    {
                        x = x * a[b[i + 1]];
                    }
                }
                if(x == 23)
                {
                    ans = "YES";
                    break;
                }
                for(int i = 4; i >= 1; i--)
                {
                    if(c[i] != 3)
                    {
                        ok = 1;
                        c[i]++;
                        for(int j = i + 1; j <= 4; j++)
                            c[j] = 1;
                        break;
                    }
                }
                if(ok == 0) break;
            }
        } while (next_permutation(b+1, b+ 6));
        cout << ans << endl;
    }
}