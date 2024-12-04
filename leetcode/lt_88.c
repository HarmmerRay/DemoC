#include <stdio.h>
#include <stdlib.h>
//
// Created by 26247 on 11/17/2024.
//
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m -1, p2 = n -1;
    for (int tail = m + n - 1;tail >= 0; tail--) {
        if (p1 == -1) {
            nums1[tail] = nums2[p2];
            p2--;
            continue;
        }
        if (p2 == -1) {
            nums1[tail] = nums1[p1];
            p1--;
            continue;
        }
        if (nums1[p1] >= nums2[p2]) {
            nums1[tail] = nums1[p1];
            p1--;
        }else {
            nums1[tail] = nums2[p2];
            p2--;
        }
    }
}

int main() {

}