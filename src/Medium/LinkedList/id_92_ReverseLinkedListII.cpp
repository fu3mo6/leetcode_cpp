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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode _dummy;
        _dummy.next = head;
        
        ListNode *prev = &_dummy, *node = head;
        
        ListNode *left = &_dummy;
        
        for(int i=0; i<m; i++){
            left = prev;
            prev = node;
            node = node->next;
        }        
        
        for(int i=m; i<n; i++){
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        
        left -> next -> next = node;
        left -> next = prev;
        
        return _dummy.next;
    }
};

// https://leetcode.com/problems/reverse-linked-list-ii/description/