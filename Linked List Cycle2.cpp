/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //http://www.cnblogs.com/springfor/p/3862125.html
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *p = head, *q = head;
        while(true)
        {
            if(q == NULL || q->next == NULL) return NULL;
            p = p->next;
            q = q->next->next;
            if(p == q) break;
        }
        while(p != head)
        {
            p = p->next;
            head = head->next;
        }
        return p;
    }
};
