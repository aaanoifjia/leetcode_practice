// trick: use dum be listNode on stack to be destroied, 
//      while dum.next are constructed on heap not to be destroyed 

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dum(0);
        ListNode* tail = &dum;
        int sum = 0;
        while (l1 || l2 || sum){
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            tail->next = new ListNode(sum % 10); // new/delete stores objects on heap, which is not destroyed when the dtor gets run
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail = tail->next;
            sum /= 10; 
        }
        return dum.next; 
    }
};