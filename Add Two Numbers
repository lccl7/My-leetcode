/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //If you can read what the code says, you can understand what the question is.
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *l3 = new ListNode(0);
        ListNode *p = l3;  
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(carry%10);
            carry /= 10;
            l3 = l3->next;
            if(carry == 1)
            {
                l3->next = new ListNode(1);
            }
        }
        return p->next;
    }
};
