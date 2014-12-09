/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //two ways to solve the problem.
 //the first one is to use three points, one before the cur, cur, and the next.
 //be careful that p may be point to NULL so in the second loop of the first method
 //we should judge whether p points to NULL or not then compare them.
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head;
        ListNode *cur = head, *p = head->next, *pre = pstart;
        while(p != NULL)
        {
            bool flag = false;
            while(p != NULL && cur->val == p->val)
            {
                p = p->next; flag = true;
            }
            if(flag)
            {
                pre->next = p;
            }
            else
            {
                pre = pre->next;
            }
            cur = p;
            if(p) p = p->next;
        }
        return pstart->next;
//    while(cur!=NULL)  
//    {  
//        while(cur->next!=NULL && pre->next->val==cur->next->val)  
//        {  
//            cur = cur->next;  
//        }  
//        if(pre->next==cur)  
//        {  
//            pre = pre->next;  
//        }  
//        else  
//        {  
//            pre->next = cur->next;  
//        }  
//        cur = cur->next;  
//    }  
//    return pstart->next;
    }
};
