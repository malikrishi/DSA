/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 *
 * Solution : Write a function to merge two lists.
 *            Create a function to iterate for half the list and merge the {0 , last}, {1, last -1 } 
 *            in each iteration and update the length. Do this till the last iteration.
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
   if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }

    
    ListNode* mergeLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val > l2->val) {
            l2->next = mergeLists(l1, l2->next);
            return l2;
        }
        l1->next = mergeLists(l1->next, l2);
        return l1;
    }
};
