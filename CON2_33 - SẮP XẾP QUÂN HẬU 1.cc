#include<bits/stdc++.h>
using namespace std;
int a[13]={1,0,0,2,10,4,40,92,352,724,2680,14200};
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	cout<<a[n-1]<<"\n";
	}
    return 0;
}