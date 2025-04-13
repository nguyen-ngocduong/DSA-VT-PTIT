#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, ans = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if(x == k)
			{
				cout << i;
				ans = 1;
			}
		}
		if(!ans) cout << "NO";
		cout << '\n';
	}
}