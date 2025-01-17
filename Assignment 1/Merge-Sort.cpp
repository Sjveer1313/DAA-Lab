#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1],b[n2];
    for(int i = 0 ; i < n1 ; i++){
        a[i] = arr[l + i];
    }
    for(int j = 0 ; j < n2 ; j++){
        b[j] = arr[mid + 1 + j];
    }

    int i = 0 , j = 0 , k = l;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}

// Recursive method
void mergeSort(int arr[],int l,int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid + 1,r);
        merge(arr,l,mid,r);
    }
}

// Iterative method
int min(int i,int j){
    return (i<j)?i:j;
}
void mergeSort1(int arr[],int n){
    int curr_size;
    int left_start;

    for(curr_size = 1 ; curr_size <= n - 1 ; curr_size = 2 * curr_size){
        for(left_start = 0 ; left_start < n - 1 ; left_start += 2 * curr_size){
            int mid = min(left_start + curr_size - 1,n - 1);
            int right_end = min(left_start + 2 * curr_size - 1,n - 1);

            merge(arr,left_start,mid,right_end);
        }
    }
}

int main(){
    int arr[] = {45,23,87,67,4,6,12};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // mergeSort(arr,0,n - 1);
    mergeSort1(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

