/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 //build an old pointer and a new pointer as a copy of the old one, then insert every new copy pointer
 //behind the old one. Next step is that put the random pointer point to the right place.
 //At last, split the old list and the new list, return the new one.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode *result = NULL;
        RandomListNode *pold = head, *pnew = result, *poldnext = NULL;
        while(pold)
        {
            RandomListNode *pnew = new RandomListNode(pold->label);
            poldnext = pold->next;
            pnew->next = poldnext;
            pold->next = pnew;
            if(result == NULL)
                result = pnew;
            pold = poldnext;
        }
        pold = head;
        while(pold)
        {
            if(pold->random)
                pold->next->random = pold->random->next;
            pold = pold->next->next;
        }
        pold = head;
        pnew = result;
        while(pnew->next)
        {
            pold->next = pnew->next;
            pold = pold->next;
            pnew->next = pold->next;
            pnew = pnew->next;
        }
        pold->next = NULL;
        pnew->next = NULL;
        return result;
    }
};
