#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    // Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    /*
    1. TwoSum - easy

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    // #include <unordered_map>
    // using namespace std;
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // O(n)/O(n) memoized
        unordered_map<int, int> mem;
        int i = 0;
        for (; !mem.count(target - nums[i]); i++)
        {
            mem[nums[i]] = i;
        }
        return {mem[target - nums[i]], i};
    }

    /*
    9. Palindrome Number - easy

    Given an integer x, return true if x is palindrome integer.

    An integer is a palindrome when it reads the same backward as forward.

    For example, 121 is a palindrome while 123 is not.
    // #include <cmath>
    */
    bool isPalindrome(int x)
    {
        // O(n), O(1)
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int r = 0;
        int i = log10(x);
        for (; i > 0; i = i - 2)
        {
            r = (r * 10) + (x % 10);
            x = x / 10;
        }
        if (i == 0)
        {
            x = x / 10;
        }
        return (r == x);
    }
    
    /*
    13. Roman to Integer
    
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

    Given a roman numeral, convert it to an integer.
    */
    int romanToInt(string s) {
        // O(n), O(1) (but O(nm) time for m different symbols)
        auto to_val = [] (string s) {
            if (s == "I") return 1;
            if (s == "V") return 5;
            if (s == "X") return 10;
            if (s == "L") return 50;
            if (s == "C") return 100;
            if (s == "D") return 500;
            if (s == "M") return 1000;
            return 0;
        };
        
        auto check_spec = [] (string s) {
            if (s == "IV") return 4;
            if (s == "IX") return 9;
            if (s == "XL") return 40;
            if (s == "XC") return 90;
            if (s == "CD") return 400;
            if (s == "CM") return 900;
            return 0;
        };
        
        int n = s.size();
        int res = 0;
        int c;
        int k = 0;
        for (; k < n - 1; k++)
        {
            if ((c = check_spec(s.substr(k, 2))))
            {
                res += c;
                k++;
            }
            else {
                res += to_val(s.substr(k, 1));
            }
        }
        if (k == n - 1) res += to_val(s.substr(k, 1));
        
        return res;
    }

    /*
    14. Longest Common Prefix
    
    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".
    */
    string longestCommonPrefix(vector<string>& strs) {
        // O(mlogn) time, O(1) heap, O(n) stack
        auto merge2 = [] (string a, string b)->string {
            int k = 0;
            for (; k < a.size(); k++) {
                if (a.substr(k, 1) != b.substr(k, 1)) return a.substr(0, k);
            }
            return a;
        };
        
        auto divide = [&strs, &merge2] (int start, int end)->string {
            auto divide_helper = [&strs, &merge2] (int start, int end, auto & div_rec)->string             {
                if (end == start) return strs[start];

                string a = div_rec(start, (start + end) / 2, div_rec);
                string b = div_rec((start + end) / 2 + 1, end, div_rec);
                return merge2(a, b);            
            };
            return divide_helper(start, end, divide_helper);
        };
        
        return divide(0, strs.size() - 1);
    }
    
    /*
    20. Valid Parentheses
    
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    */
    bool isValid(string s) {
        // O(n)/O(n)
        vector<string> stack;
        string c;
        for (int k = 0; k < s.size(); k++) {
            c = s.substr(k, 1);
            if (c == "}") {
                if (!stack.size() || stack.back() != "{") return false;
                stack.pop_back();
            }
            else if (c == ")") {
                if (!stack.size() || stack.back() != "(") return false;
                stack.pop_back();
            }
            else if (c == "]")
            {
                if (!stack.size() || stack.back() != "[") return false;
                stack.pop_back();
            }
            else
            {
                stack.push_back(c);
            }
        }
        return stack.size() == 0;
    }
    
    /*
    26. Remove Duplicates from Sorted Array
    
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

    Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

    Return k after placing the final result in the first k slots of nums.

    Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
    */
    int removeDuplicates(vector<int>& nums)
    {
        // O(n), O(1)
        int n = nums.size();
        int p = nums[0];
        int k = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != p)
            {
                swap(nums[k], nums[i]);
                p = nums[k];
                k++;
            }
        }
        
        return k;
    }
    
    /*
    108. Convert Sorted Array to Binary Search Tree
       
    Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
    */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        TreeNode* n = new TreeNode();
        n->val = nums[(end + start)/2];
        
        if (start == end)
        {
            n->left = nullptr;
            n->right = nullptr;
        } else
        {
            int i = (end + start)/2 -1;
            n->left = (start > i) ? nullptr : sortedArrayToBSTHelper(nums, start, i);
            i = (end + start)/2 + 1;
            n->right = (i > end) ? nullptr : sortedArrayToBSTHelper(nums, i, end);            
        }
        return n;
    }
    
    
    /*
    206. Reverse Linked List

    Given the head of a singly linked list, reverse the list, and return the reversed list.
    */
    ListNode *reverseList(ListNode *head)
    {

        // iterative O(n)/O(1)
        //         if (!head) return NULL;

        //         ListNode* prev = head;
        //         ListNode* temp = head->next;
        //         head = temp;
        //         prev->next = NULL;

        //         while(head) {
        //             temp = head->next;
        //             head->next = prev;
        //             prev = head;
        //             head = temp;
        //         }

        //         return prev;

        // recursive O(n)/O(n) stack, O(1) heap
        return rec_helper(head, NULL);
    }

    ListNode *rec_helper(ListNode *head, ListNode *prev)
    {
        if (!head)
            return prev;

        ListNode *temp = head->next;
        head->next = prev;
        return rec_helper(temp, head);
    }
};
