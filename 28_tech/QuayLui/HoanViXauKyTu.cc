#include<bits/stdc++.h>
using namespace std;
// int main (){
//     int t; cin >> t;
//     while(t--){
//         string s; cin >> s;
//         sort(s.begin(), s.end());
//         do{
//             cout << s << " ";
//         }while(next_permutation(s.begin(), s.end()));
//         cout << endl;
//     }
//     return 0;
// }
int n,a[1000], used[1000];
string s;
void init(){
    cin >> s;
    memset(used, 0, sizeof(used));
    n = s.length();
}
void Try(int i){
    for(int j = 0; j<n; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = 1;
            if(i == n-1){
                for(int k = 0; k<n; k++){
                    cout << s[a[k]];
                }
                cout << " ";
            }
            else {
                Try(i + 1);
            }
            used[j] = 0; 
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        Try(0);
        cout << endl;
    }
    return 0;
}