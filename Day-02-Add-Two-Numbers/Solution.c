/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */ 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *helper = result;
    int addDigit = 0;
    
    while(l1 || l2 || addDigit) {
        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = addDigit;
        
        if(l1) {
            node->val += l1->val;
            l1 = l1->next;
        }
        
        if(l2) {
            node->val += l2->val;
            l2 = l2->next;
        }
        
        addDigit = node->val / 10;
        node->val = node->val % 10;
        
        helper->next = node;
        helper = helper->next;
    }
    
    return result->next;
    
}
