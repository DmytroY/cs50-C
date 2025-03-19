#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    // val is value to be removed
    int k = numsSize; // size of resulting array
    for(int i = 0; i < numsSize; i++) {
        
        while(nums[i] == val){
            // the member of nums = val
            // we should shift array tail one position left
            for(int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
            k--;
            // dummy value to the end of array, must be != val
            nums[numsSize - 1] = 255;
        }

        for(int l = 0; l < numsSize; l++) {
            printf("  %d  ",  nums[l]);
        }
        printf ("\n");
    }
    return k;
    
}

int main() {
    int nums[] = {3,2,2,3};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int val = 3;

    int k = removeElement(nums, numsSize, val);
    printf("k = %d\n", k);
    for(int i = 0; i < k; i++) {
        printf(" %d,", nums[i]);
    }
    printf("\n");

    return 0;
}
