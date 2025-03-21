#include <stdio.h>
#include <stdbool.h>

bool validMountainArray(int* arr, int arrSize){
    // check forward slope, find the peak
    int peak = 0;
    for(int i = 0; i < arrSize -1; i++) {
        if(arr[i] < arr[i+1]){
            peak = i + 1;
        } else {
            break;
        }
    }

    //in case of peak at the begining or at the end it is not thrue montain
    if(!peak || peak == arrSize - 1) {return false;}

    // check back slope
    for(int i = peak; i < arrSize - 1; i++) {
        if(arr[i] <= arr[i+1]){
            return false;
        }
    }
    return true;
}

int main() {

    int arr[] = {-1,1,10,13};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("%s", validMountainArray(arr, arrSize) ? "true" : "false");

    return 0;
}