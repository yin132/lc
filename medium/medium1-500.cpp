
class Solution {
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // iterative O(n)/O(n)
        
        ListNode* prev = nullptr;
        ListNode * res;
        int v;
        int o = 0;
        
        auto add_node = [&] () {
            if (v > 9) {
                o = 1;
                v -= 10;
            }
            else {
                o = 0;
            }
            
            res = new ListNode();
            res->next = prev;
            res->val = v;
            prev = res;
        };
        
        while (l1 && l2) {
            v = l1->val + l2->val + o;
            
            add_node();
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            v = l1->val + o;
            
            add_node();
            
            l1 = l1->next;
        }
        
        while (l2) {
            v = l2->val + o;

            add_node();
            
            l2 = l2->next;
        }
        
        if (o) {
            res = new ListNode();
            res->next = prev;
            res->val = 1;
        }
        
        return rec_helper(res, nullptr);
    }
    
    ListNode* rec_helper(ListNode* head, ListNode* prev) {
        if (!head) return prev;

        ListNode* temp = head->next;
        head->next = prev;
        return rec_helper(temp, head);
    }
};