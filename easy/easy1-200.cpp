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
    
/* 
9. Palindrome Number - easy

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

 */
    bool isPalindrome(int x) {
        // O(n), O(1)
        if (x < 0) return false;
        if (x == 0) return true;
        int r = 0;
        int i = log10(x);
        for (; i > 0; i = i - 2) {
            r = (r * 10) + (x % 10);
            x = x / 10;
        }
        if (i == 0) {
            x = x / 10;
        }
        return (r == x);
    }
};
