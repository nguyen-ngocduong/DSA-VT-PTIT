#include<bits/stdc++.h>
using namespace std;
/*int a[13]={1,0,0,2,10,4,40,92,352,724,2680,14200};
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	cout<<a[n-1]<<"\n";
	}
    return 0;
}*/
int n,X[1005], cot[1005], d1[1005], d2[1005];
int cnt;
void init(){
	cin >> n;
	cnt = 0;
	memset(cot,0,sizeof(cot));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
}
void Try(int i){
	for(int j = 1; j<=n; j++){
		if(cot[j] == 0 && d1[i-j+n] == 0 && d2[i+j-1] == 0) {
			X[i] = j;
			cot[j] = 1;
			d1[i-j+n] = 1;
			d2[i+j-1] = 1;
			if(i == n){
				cnt++;
			}
			Try(i+1);
			cot[j] = 0;
			d1[i-j+n] = 0;
			d2[i+j-1] = 0;
		} 
	}
}
int main(){
	int t; cin >> t;
	while (t--)
	{
		init();
		Try(1);
		cout << cnt << endl;
	}
	return 0;	
}