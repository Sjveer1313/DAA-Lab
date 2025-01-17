#include<iostream>
#include<vector>
using namespace std;
int maxCrossSum(int arr[],int l,int mid,int r){
    int sum = 0;
    int left_sum = INT_MIN;
    // for left sub array
    for(int i = mid ; i >= l ; i--){
        sum = sum + arr[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }
    // for right sub array
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid + 1 ; i <= r ; i++){
        sum = sum + arr[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }
    // total
    return (left_sum+right_sum);
}
int maxSum(int arr[],int l,int r){
    if(l > r){
        return INT_MIN;
    }
    if(l == r){
        return l;
    }

    int mid = l + (r - l) / 2;
    int left_sum = maxSum(arr,l,mid);
    int right_sum = maxSum(arr,mid + 1,r);
    int crossSum = maxCrossSum(arr,l,mid,r);

    // Returning max of the three
    if(left_sum >= right_sum && left_sum >= crossSum){
        return left_sum;
    }
    else if(right_sum >= left_sum && right_sum >= crossSum){
        return right_sum;
    }
    else{
        return crossSum;
    }
}
int main(){
    int arr[] = {3,5,-8,7,-3,2,3};
    int n = sizeof(arr)/sizeof(int);
    cout << maxSum(arr,0,n - 1) << endl;
    return 0;
}