class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return _sortedListToBST(head, NULL);
    }
    
    TreeNode* _sortedListToBST(ListNode* head, ListNode* tail) {
        
        if(head == tail)
            return NULL;
        if(head->next==tail){
            return new TreeNode (head -> val);
        }
        
        ListNode *mid, *tmp;
        mid = head;
        tmp = head;
        while(tmp != tail && tmp->next != tail){
            mid = mid -> next;
            tmp = tmp -> next -> next;
        }
        
        TreeNode* root = new TreeNode (mid -> val);
        root->left = _sortedListToBST(head, mid);
        root->right =  _sortedListToBST(mid->next, tail);
        
        return root;
    }
};

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/