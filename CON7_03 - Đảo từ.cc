#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin >>  t;
    cin.ignore();
    while (t--)
    {
        string s,word;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> word){
            reverse(begin(word), end(word));
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}