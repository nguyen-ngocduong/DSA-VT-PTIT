#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    deque<int> q;
    while(t--){
        string s; cin >> s;
        int num;
        if(s == "PUSHFRONT") {
            cin >> num;
            q.push_front(num);
        }
        else if(s == "PRINTFRONT"){
            if(!q.empty()) cout << q.front() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POPFRONT"){
            if(!q.empty()) q.pop_front();
        }
        else if(s == "PUSHBACK") {
            cin >> num;
            q.push_back(num);
        }
        else if(s == "PRINTBACK"){
            if(!q.empty()) cout << q.back() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POPBACK"){
            if(!q.empty()) q.pop_back();
        }
    }
    return 0;
}