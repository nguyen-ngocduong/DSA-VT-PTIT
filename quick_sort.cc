#include<bits/stdc++.h>
using namespace std;
int patition(int a[], int left, int right){
    int pivot = a[right];
    int pointer = left;
    for(int i = left; i<= right; i++){
        if(a[i] < pivot) {
            swap(a[i], a[pointer]);
            pointer += 1;
        }
    }
    swap(a[right], a[pointer]);
    return pointer;
}
void quick_sort(int a[], int left, int right){
    if(left < right){
        int tmp = patition(a,left,right);
        quick_sort(a,left, tmp - 1);
        quick_sort(a,tmp+1, right);
    }
}
int main(){
    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        quick_sort(a,0,n-1);
        for(int i = 0; i<n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}