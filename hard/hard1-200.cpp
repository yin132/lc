#include <unordered_map>
using namespace std;


class Solution {
public:
/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/
    int firstMissingPositive(vector<int>& nums) {
        // O(n) runtime, O(1) memory
        // swap elements into place, look for first discontinuity
        int c;
        int i;
        for (int k = 0; k < nums.size(); k++) {
            c = nums[k];
            while (c > 0 && c <= nums.size() && c != nums[c-1]) {
                nums[k] = nums[c-1];
                nums[c-1] = c;
                c = nums[k];
            }
        }
        for (int k = 1; k <= nums.size(); k++) {
            if (nums[k - 1] != k) {
                return k;
            }
        }
        return nums.size() + 1;
    }
};