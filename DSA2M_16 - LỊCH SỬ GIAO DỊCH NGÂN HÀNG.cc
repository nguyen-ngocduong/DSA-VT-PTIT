#include<bits/stdc++.h>
using namespace std;
struct giaodich{
    int ngay, tien;
    string loaigd;
};
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        giaodich a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i].ngay >> a[i].tien >> a[i].loaigd;
        }
        for(int i = n-1; i>=0; i--){
            cout << a[i].ngay << " " << a[i].tien << " " << a[i].loaigd << endl;
        }
    }
    return 0;
}