#include <stdio.h>
//
// Created by 26247 on 12/4/2024.
// 处理边界、处理极端、处理逻辑
// int removeElement(int* nums, int numsSize, int val) {
//     int head = 0, tail = numsSize - 1;
//     while (head <= tail) {
//         if (nums[head] == val) {
//             while (nums[tail] == val) {
//                 tail--;
//             }
//             if (tail == -1) {
//                 break;
//             }
//             nums[head] = nums[tail];
//             tail--;
//             head++;
//         }else {
//             head++;
//         }
//     }
//     return tail+1;
// }
int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}


int main() {
    int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 1;
    printf("%d\n", removeElement(nums, numsSize, val));
}