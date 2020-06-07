class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode *head = NULL, *tail = NULL;
        ListNode *curr, *v1 = head1, *v2 = head2;
        int extra = 0;
        
        while(v1 != NULL || v2 != NULL || extra !=0)
        {
            curr = new ListNode(extra);
            extra = 0;
            
            if(v1 != NULL){
                extra += (curr->val + v1->val) / 10;
                curr->val = (curr->val + v1->val) % 10;
                v1 = v1->next;
            }
            
            if(v2 != NULL){
                extra += (curr->val + v2->val) / 10;
                curr->val = (curr->val + v2->val) % 10;
                v2 = v2->next;
            }
            
            if(head == NULL){
                head = curr;
                tail = head;
            }
            else {
                tail->next = curr;
                tail = tail->next;
            }
        }
        return head;
    }
};

// https://leetcode.com/problems/add-two-numbers/description/