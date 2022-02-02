#include <unordered_map>
using namespace std;


class Solution {
public:
/* 
1. TwoSum - easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

// #include <unordered_map>
// using namespace std;
 */
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n)/O(n) memoized
        vector<int> ret(2);
        unordered_map<int, int> mem;
        for (int i = 0; ;i++) {
            int c = nums[i];
            if (mem.count(target - c)) {
                ret[1] = i;
                ret[0] = mem[target - c];
                return ret;
            }
            mem[c] = i;
        }
        return ret;
    }
};