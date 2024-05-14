class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head->next;
        ListNode *pre = head;
        while(curr){
            ListNode *node= new ListNode(__gcd(curr->val,pre->val));
            node->next = curr;
            pre->next = node;
            pre=curr;
            curr=curr->next;
        }
        return head;
    }
};