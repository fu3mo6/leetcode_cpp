class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *node = head;
        int len = 1;
        
        if(!head)
            return NULL;
        
        while(node->next != NULL){
            node = node->next;
            len++;
        }
        node->next = head;
        
        k = len - k % len;
        for(int i=0; i<k; i++)
            node = node -> next;
        
        head = node->next;
        node->next = NULL;
        return head;
    }
};

// https://leetcode.com/problems/rotate-list/description/