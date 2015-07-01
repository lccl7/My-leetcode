/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //build two listhead point to the pointer whose value less than val and 
 //more than val respectively, then link them together.
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL) return head;
        ListNode *pstart1 = new ListNode(0);
        ListNode *pstart2 = new ListNode(0);
        ListNode *p = pstart1, *q = pstart2;
        while(head != NULL)
        {
            if(head->val < x)
            {
                pstart1->next = head;
                pstart1 = pstart1->next;
            }
            else
            {
                pstart2->next = head;
                pstart2 = pstart2->next;
            }
            head = head->next;
        }
        pstart1->next = q->next;
        pstart2->next = NULL;
        return p->next;
    }
};
