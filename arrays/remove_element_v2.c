#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val) {
    // val is value to be removed
    int k = 0;

    // create copy of nums array
    int* arr2 = malloc(numsSize * sizeof(nums[0]));
    memcpy(arr2, nums, numsSize * sizeof(nums[0]));

    // copy from arr2 to nums only correct members
    for (int i = 0; i < numsSize; i++) {
        if(arr2[i] != val) {
            nums[k] = arr2[i];
            k++;
        }
    }
    free(arr2);
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
