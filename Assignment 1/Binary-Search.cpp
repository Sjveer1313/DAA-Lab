// Iterative method
#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int x){
    int s = 0;
    int e = n - 1;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}

// Recursive method
int binary(int arr[],int s,int e,int target){
    while(e >= s){
        int mid = s + (e - s) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            return binary(arr,mid + 1,e,target);
        }
        else{
            return binary(arr,s,mid - 1,target);
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    int target;
    cout << "Enter the number to be searched : ";
    cin >> target;
    int x = binarySearch(arr,n,target);
    int y = binary(arr,0,n,target);
    if(x == -1 && y == -1){
        cout << "The number is not present in the array." << endl;
    }
    else{
        cout << "The target number " << target << " is at index : " << x << " " <<  y << endl;
    }
    return 0;
}


