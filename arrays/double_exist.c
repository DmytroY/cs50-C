#include <stdio.h>
#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize) {
    for(int i = 0; i < arrSize-1; i++){
        for(int j = i + 1; j < arrSize; j ++){
            if(arr[i] == 2*arr[j] || arr[j] == 2*arr[i]){
                return true;
            }
        }
    } 
    return false;
}

int main() {

    int arr[] = {-2,0,10,-19,4,0,6,-8};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("%s", checkIfExist(arr, arrSize) ? "true" : "false");

    return 0;
}
