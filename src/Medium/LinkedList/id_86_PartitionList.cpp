class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode _left, _right;
        ListNode *left = &_left, *right = &_right;
        ListNode *node = head;
        
        _left.next = NULL;
        _right.next = NULL;
        
        while(node)
        {
            if(node->val < x)
            {
                left -> next = node;
                left = left -> next;
            }
            else
            {
                right -> next = node;
                right = right -> next;
            }
            node = node -> next;
        }
        
        right -> next = NULL;
        left -> next = _right.next;
        
        return _left.next;
    }
};
// https://leetcode.com/problems/partition-list/description/