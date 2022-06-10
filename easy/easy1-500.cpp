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