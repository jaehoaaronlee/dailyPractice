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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL || k == 1) return head;
        ListNode *tmpHead = new ListNode(-1);
        tmpHead->next = head;
        ListNode *cur = tmpHead, *nxt, *prev = tmpHead;
        
        int numNodes = 0;
        while (cur = cur->next)
            ++numNodes;
        
        while (numNodes >= k) {
            cur = prev->next;
            nxt = cur->next;
            
            for(int i = 1; i < k; ++i) {
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt=cur->next;
            }
            prev = cur;
            numNodes -= k;
        }
        
        return tmpHead->next;
        
    }
};
