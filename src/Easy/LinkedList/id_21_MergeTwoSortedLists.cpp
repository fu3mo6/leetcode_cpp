
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;        
        if(!list2)
            return list1;
        
        if(list1->val > list2->val){
            list2 -> next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        else {
            list1 -> next = mergeTwoLists(list1->next, list2);
            return list1;
            
        }
    }        
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        if(!list1)
            return list2;
        
        if(!list2)
            return list1;
        
        if(list1->val > list2->val)
            return mergeTwoLists(list2, list1);
                
        ListNode *front, *back;
        
        front = list1;
        back = list1;
        list1 = list1 -> next;
        
        while(list1 || list2){
            if(!list1){
                back->next = list2;
                break;
            }
            
            if(!list2){
                back->next = list1;
                break;
            }
            
            if(list1->val < list2->val){
                back->next = list1;
                list1 = list1 -> next;
                back = back -> next;
            }
            else {
                back->next = list2;
                list2 = list2 -> next;
                back = back -> next;
            }            
        }
        return front;
    }    
};


// https://leetcode.com/problems/valid-parentheses/description/
// #recursion #list
