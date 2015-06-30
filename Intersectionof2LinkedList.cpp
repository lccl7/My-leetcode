/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Let i and j recordd the length of A and B, respectively. 
 //Then ignore |i-j| points then A and B have the same length.
 //Next move A and B at the same time and we can find where they intersect.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *pstart = new ListNode(0);
        ListNode *a = headA, *b = headB;
        int i = 0, j = 0;
        while(headA != NULL)
        {
            headA = headA->next;
            ++i;
        }
        while(headB != NULL)
        {
            headB = headB->next;
            ++j;
        }
        if(i > j)
        {
            int n = i-j;
            while(n > 0)
            {
                a = a->next;
                --n;
            }
        }
        else
        {
            int n = j - i;
            while(n > 0)
            {
                b = b->next;
                --n;
            }
        }
        while(a != NULL && b != NULL)
        {
            if(a == b)
            {
                pstart->next = a;
                break;
            }
            else
            {
                a = a->next;
                b = b->next;
            }
        }
        return pstart->next;
    }
};
Method II
//Maintain two pointers pA and pB initialized at the head of A and B, respectively. 
//Then let them both traverse through the lists.When pA reaches the end of a list,
//then redirect it to the head of B (yes, B, that's right.); 
//similarly when pB reaches the end of a list, redirect it the head of A.
//If at any point pA meets pB, then pA/pB is the intersection node.
//If two lists have intersection, then their last nodes must be the same one. 
//So when pA/pB reaches the end of a list, record the last element of A/B respectively. 
//If the two last elements are not the same one, then the two lists have no intersections.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *a = headA, *b = headB;
        ListNode *ta, *tb;
        while(1)
        {
            if(headA == NULL)
                headA = b;
            if(headB == NULL)
                headB = a;
            if(headA->next == NULL)
                ta = headA;
            if(headB->next == NULL)
                tb = headB;
            if(ta != tb && ta != NULL && tb != NULL)
                return NULL;
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
    }
};
