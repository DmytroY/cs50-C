#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = 1;

    while(k < numsSize) {
        if(nums[k] == nums[k-1]) {
            // shift left
            for(int i = k; i < numsSize - 1; i++) {
                nums[i] = nums [i + 1];
            }
            numsSize--;
        } else {
            k++;
        }
    }
    return k;
}

int main() {
    //int nums[] = {-2,-1,-1,0,0,0,1,2,2,2,3,3};
    int nums[] = {1,1,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    int k = removeDuplicates(nums, numsSize);
    printf("k = %d\n", k);
    for(int i = 0; i < k; i++) {
        printf(" %d,", nums[i]);
    }
    printf("\n");

    return 0;
}
