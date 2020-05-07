
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *now = head;
        ListNode *prev = NULL;
        ListNode *tmp;
        
        while(now)
        {
            tmp = now -> next;
            now -> next = prev;
            prev = now;
            now = tmp;
        }
        
        return prev;
    }
};


// https://leetcode.com/problems/reverse-linked-list/description/
// #LinkedList #Reverse