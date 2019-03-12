/**
 * Given an array of integers, return indices of the two numbers such that they 
 * add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may 
 * not use the same element twice.
 */
#include <stdio.h>
int* twoSum(int *nums, int numSize, int target) 
{
    int i, j;
    static int ret[2] = {0};

    if (nums == NULL) {
        return NULL;
    }

    for (i = 0; i < numSize; i++) {
        j = i + 1;
        for (j = i + 1; j < numSize; j++){
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return NULL;
}

void test()
{
    int nums_t[4] = {1, 7, 11, 15};
    int target = 8;
    int *ret;

    ret = twoSum(nums_t, sizeof(nums_t), target);
    printf("target=%d, ret=(%d, %d)\n", target, ret[0], ret[1]);
}

int main(int argc, char *argv[])
{
    test();
}