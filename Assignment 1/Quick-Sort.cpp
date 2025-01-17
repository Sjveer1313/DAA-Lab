#include<iostream>
#include<stack>
using namespace std;
int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l - 1;

    for(int j = l ; j < r ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i + 1],arr[r]);
    return i+1;
}

// Recursive method
void quickSort1(int arr[],int l,int r){
    if(r > l){
        int p = partition(arr,l,r);
        quickSort1(arr,l,p-1);
        quickSort1(arr,p+1,r);
    }
}

// Iterative method
void quickSort2(int arr[],int l,int r){
    int stack[r - l + 1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;

    while(top >= 0){
        r = stack[top--];
        l = stack[top--];

        int p = partition(arr,l,r);
        if(p - 1 > l){
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if(p + 1 < r){
            stack[++top] = p + 1;
            stack[++top] = r;
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
    // quickSort1(arr,0,n - 1);
    quickSort2(arr,0,n - 1);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}