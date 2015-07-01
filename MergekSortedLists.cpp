/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //merge every pair first, then together.
 //loop method or recursive method.
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        while(n > 1)
        {
            int k = (n+1)/2;
            for(int i = 0; i < n/2; ++i)
                lists[i] = merge2Lists(lists[i], lists[i+k]);
            n = k;
        }
        return lists[0];
    }
    ListNode *merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p1 = new ListNode(0);
        ListNode *p = p1;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                p1->next = l1;
                l1 = l1->next;
            }
            else
            {
                p1->next = l2;
                l2 = l2->next;
            }
            p1 = p1->next;
        }
        if(l1) p1->next = l1;
        if(l2) p1->next = l2;
        return p->next;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        return mergelist(lists, 0, n-1);
    }
    ListNode *mergelist(vector<ListNode *> &lists, int start, int end)
    {
        if(start == end) return lists[start];
        int mid = (start + end)/2;
        ListNode *head1 = mergelist(lists, start, mid);
        ListNode *head2 = mergelist(lists, mid+1, end);
        merge2Lists(head1, head2);
    }
    ListNode *merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p1 = new ListNode(0);
        ListNode *p = p1;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                p1->next = l1;
                l1 = l1->next;
            }
            else
            {
                p1->next = l2;
                l2 = l2->next;
            }
            p1 = p1->next;
        }
        if(l1) p1->next = l1;
        if(l2) p1->next = l2;
        return p->next;
    }
};
