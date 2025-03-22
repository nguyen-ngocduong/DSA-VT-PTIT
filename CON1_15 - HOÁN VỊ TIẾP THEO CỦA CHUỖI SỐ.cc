#include<bits/stdc++.h>
using namespace std; 
void next(string s){
    int i = s.size() - 2;
    while(i >= 0 && s[i] >= s[i+1]){ // khi nao s[i] >= s[i+1] => dich sang trai
        i--;
    }
    if(i == -1){
        cout << "BIGGEST" << endl;
    }
    else{ // tim ki tu dau tien ben phai >= hien tai 
        int j = s.size() - 1;
        while(s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        cout << s << endl;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int tc; cin >> tc;
        string s; cin >> s;
        cout << tc << " ";
        next(s);
    }
    return 0;
}