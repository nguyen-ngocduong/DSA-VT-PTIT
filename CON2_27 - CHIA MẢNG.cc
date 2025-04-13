#include<bits/stdc++.h>
using namespace std;

int n,k,a[100],res,sum;
bool vs[100], mark;

void init(){
	cin >> n >> k;
	sum = 0;
	for(int i = 1; i <=n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	memset(vs,false,sizeof(vs));
	mark = false;
}
void Try(int cnt, int S, int sum){
	if(mark) return;
	if(cnt == k){
		mark = true;
		return;
	}
	for(int i = 1; i <=n ; ++i){
		if(!vs[i]){
			vs[i] = true;
			if(sum / k > S){
				Try(cnt+1,S + a[i], sum);
			}
			else if(sum/k == S){
				Try(cnt,0,sum);
			}
			vs[i] = false;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		init();
		if(sum % k != 0) cout << 0;
		else{
			Try(0,0,sum);
			if(mark) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
}