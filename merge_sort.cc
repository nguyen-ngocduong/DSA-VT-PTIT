#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int temp[], int left, int right, int mid){
    int i = left;
    int k = left;
    int j = mid + 1;
    while(i<=mid && j <= right){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid) { // sao chep cac ptu con lai cua a vao temp
        temp[k++] = a[i++];
    }
    while(j <= right) {
        temp[k++] = a[j++];
    }
    for(int i = left; i<=right; i++){
        a[i] = temp[i];
    }
}

void merge_sort(int a[], int temp[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/ 2;
        merge_sort(a,temp,left,mid);
        merge_sort(a,temp,mid+1,right);
        merge(a,temp,left,right,mid);
    }
}
int main(){
    int tc; cin>>tc;
    while(tc--)  {
        int n; cin>>n;
        int a[n], temp[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        merge_sort(a,temp, 0,n-1);
        for(int i = 0; i<n; i++){
            cout << a[i]<<' ';
        }
        cout << endl;
    }
    return 0;
}