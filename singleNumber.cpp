/*
Given an array of integers, every element appears twice except for one. Find that single one.
给出一组整数，每一个元素都出现两次，只有一个元素出现一次，请找出那个元素。

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
应该能找到O(N)时间复杂度的算法，并且尽可能使用更少的空间。
*/

/* Bit Manipulation：将数组中的每个元素两两异或，最后的结果就是那个只出现一次的值 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i=0; i<n; i++){
            result = result ^ A[i];
        }
        return result;
    }
};

/* hashTabl算法：时间复杂度O(N),空间复杂度O(N) */
