class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head;
        ListNode *right = left;
        
        for(int i=0; i<n; i++){
            if (!right) return NULL; // unlikely
            right = right -> next;
        }
        
        if(!right)
        {
            head = head -> next;
            //free(left);
        }
        else {
            while(right)
            {
                if(!right->next)
                {
                    // remove left->next
                    ListNode* tmp = left->next;
                    left->next = tmp -> next;
                    //free(tmp);
                    break;
                }
                right = right -> next;
                left = left -> next;
            }
        }
        return head;
    }
};

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/