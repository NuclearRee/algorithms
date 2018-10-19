#include <iostream>
struct Array{
    int left;
    int right;
    int sum;
};
Array FindMaxCrossingSubarray(int *A,int low,int mid,int high){
    int left_sum = 0;
    int sum = 0;
    int max_left = 0;
    for(int i=mid;i>=low;i--){
        sum = sum + A[i];
        if(i == mid){
            left_sum = sum;
            max_left = i;
        }
        else if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    int right_sum = 0;
    int max_right = 0;
    for(int j=mid+1;j<=high;j++){
        sum = sum + A[j];
        if(j == mid+1){
            right_sum = sum;
            max_right = j;
        }
        else if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    Array array;
    array.left = max_left;
    array.right = max_right;
    array.sum = left_sum + right_sum;
    return array;
}

Array FindMaximumSubarray(int *A,int low,int high){
    Array array,array_left,array_right,array_mid;
    if(high == low){
        array.left = low;
        array.right = high;
        array.sum = A[low];
        return array;
    }
    else{
        int mid = (low + high) / 2;
        array_left = FindMaximumSubarray(A,low,mid);
        array_right = FindMaximumSubarray(A,mid+1,high);
        array_mid = FindMaxCrossingSubarray(A,low,mid,high);
        if(array_left.sum >= array_right.sum && array_left.sum >= array_mid.sum)
            return array_left;
        else if(array_right.sum >= array_left.sum && array_right.sum >= array_mid.sum)
            return array_right;
        else if(array_mid.sum >= array_left.sum && array_mid.sum >= array_right.sum)
            return array_mid;

    }
}

int main(){
    int A[] ={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    Array array = FindMaximumSubarray(A,0,15);
    std::cout<< array.left <<" "<<array.right << " "<< array.sum <<std::endl; 
    return 0;
}