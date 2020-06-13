/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        if(!head -> next)
            return head;
        
        ListNode _dummy;
        _dummy.next = head;
        _dummy.val = head->val - 1; // Always the smallest
        
        ListNode *left = &_dummy, *right = left->next, *mid = right;
        while(right)
        {
            if(right->next && right->next->val == right->val)
            {
                right = right -> next;
            }
            else {
                if(mid == right) {
                    left = left -> next;
                    right = right -> next;
                    mid = right;
                }
                else {
                    while(mid != right) {
                        ListNode* tmp = mid;
                        mid = mid -> next;
                        delete(tmp);
                    }
                    
                    right = right -> next;
                    left -> next = right;
                    delete (mid);
                    mid = right;
                }
            }
        }
        return _dummy.next;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/