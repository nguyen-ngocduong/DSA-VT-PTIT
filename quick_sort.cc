#include<bits/stdc++.h>
using namespace std;
int partition(int left, int right, int a[]){
    int pointer = left;
    int pivot = a[right];
    for(int i = left; i<= right; i++){
        if(a[i] <= pivot){
            swap(a[i], a[pointer]);
            pointer += 1;
        }
    }
    swap(a[pointer], a[right]);
    return pointer;
}
void quick_sort(int left, int right, int a[]){
    if(left < right){
        int p = partition(left, right, a);
        quick_sort(left, p-1,a);
        quick_sort(p+1, right,a);
    }
}
int main(){
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        int a[n];
        for(int i = 0; i<n;i++){
            cin >> a[i];
        }
        quick_sort(0,n-1,a);
        for(int i=0;i<n-1;i++){
            cout << a[i]<< " ";
        }
        cout << endl;
    }
    return 0;
}