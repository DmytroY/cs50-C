#include <stdio.h>
#include <stdbool.h>

bool validMountainArray(int* arr, int arrSize){
    int peak = 0;
    for(int i = 0; i < arrSize -1; i++) {
        if(arr[i] < arr[i+1]){
            peak = i + 1;
        } else {
            break;
        }
    }
    printf("peak is %d\n", peak);
    if(!peak || peak == arrSize - 1) {return false;}

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