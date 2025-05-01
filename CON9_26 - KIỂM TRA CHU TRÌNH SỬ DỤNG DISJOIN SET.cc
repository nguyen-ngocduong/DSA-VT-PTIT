#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int n, check[maxn], cycle;
int a[maxn][maxn];

void dfs(int u, int p)
{
	check[u]=1;
	for(int v=1;v<=n;v++)
	{
		if(a[u][v])
		{
			if(!check[v]) dfs(v,u);
			else if(v!=p) cycle=1;
		}
	}
}
void solution()
{
	cin >> n;
	memset(a,0,sizeof(a));
	memset(check,0,sizeof(check));
	cycle=0;
	for(int i=1;i<n;i++)
	{
		int x, y;
		cin >> x >> y;
		a[x][y]=1;
		a[y][x]=1;
	}
	dfs(1,0);
	if(cycle) cout << "NO";
	else cout << "YES";
}
main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solution();
		cout << endl;
	}
}