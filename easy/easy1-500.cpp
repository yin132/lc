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
        } else {
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
