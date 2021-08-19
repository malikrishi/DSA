/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (NULL == head1) return head2;
    if (NULL == head2) return head1;
    
    if (head1->val > head2->val) {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
    
    head1->next = mergeTwoLists(head1->next, head2);
    return head1;
    }
};
