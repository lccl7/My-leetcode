/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Build a fake head to ease the problem.
 //Then use two points (pfast and pslow) to detect where the deleting point is.
 //pfast begins at n, pslow begins at fake head, so when pfast->next reaches the end,
 //pslow points the point before deleting point, then we can just delete it.
 //An advantage of using fake head is we need not worry about deleting head if
 //it is deleting point.
 //in the fist while loop, the condition pfast != NULL may not be needed, but 
 //running time will be longer.
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head;
        ListNode *pslow = pstart, *pfast = head;
        while(--n > 0  && pfast != NULL)
        {
            pfast = pfast->next;
        }
        while(pfast->next != NULL)
        {
            pslow = pslow->next;
            pfast = pfast->next;
        }
        pslow->next = pslow->next->next;
        return pstart->next;
    }
};
