class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        if(!head)
            return false;
        
        while(slow->next && fast->next && fast->next->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow==fast) return true;
        }
        return false;
    }
};


// https://leetcode.com/problems/linked-list-cycle/description/
// #LinkedList #TwoPointerTechnique