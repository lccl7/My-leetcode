/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //build a fakehead pointing to head, so when we return we can find where head is
 //In the program we swap point p and point p->next
 //First we record p->next->next by nextstart and then we can swap p and p->next
 //when ending swap we should link nextstart next to p, then move pre and p .
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head;
        ListNode *pre = pstart, *p = head;
        while(p != NULL && p->next != NULL)
        {
            ListNode *nextstart = p->next->next;
            p->next->next = p;
            pre->next = p->next;
            p->next = nextstart;
            pre = p;
            p = pre->next;
        }
        return pstart->next;
    }
};
