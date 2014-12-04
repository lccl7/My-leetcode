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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        //the node pre and tmp is the place where the element is inserted.
        //node pre and tmp is the head of the list(when p is the smallest element)
        //or reached where p is just between them.
        //the node p is the element that will be compared and inserted.
        //but you should record that where we have reached, so pend is the element that before p.
        //If the p equals tmp then we know that p is bigger than any element in the sorted list. 
        //If not, we find the place where p can be sorted, and put it in place, which is in the 
        // else statement. then p can point to the next unsorted list.
        ListNode *p = head->next, *pstart = new ListNode(0);
        ListNode *pend = head;
        pstart->next = head;
        while(p != NULL)
        {
            ListNode *tmp = pstart->next, *pre = pstart;
            while(tmp != p && p->val >= tmp->val) 
            {
                tmp = tmp->next;
                pre = pre->next;
            }
            if(tmp == p) pend = p;
            else
            {
                pend->next = p->next;
                pre->next = p;
                p->next = tmp;
            }
            p = pend->next;
        }
        head = pstart->next;
        delete pstart;
        return head;
    }
};
