/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Three Steps: 1.Split the list into two parts
//2. Reverse the second part.
//3. Merge the two list as one.
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        splitlist(head);
    }
    void splitlist(ListNode *head)
    {
        ListNode *fast = head, *slow = head, *tail;
        while(fast != NULL && fast->next != NULL)
        {
            tail = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        tail->next = NULL; 
        reverseList(slow); //slow是后半部分的开始
        mergeList(head, slow, tail);
    }
    void reverseList(ListNode* &head)
    {
        if(head == NULL || head->next == NULL) return;
        ListNode *pre = head, *cur = pre->next;
        while(cur != NULL)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next = NULL;
        head = pre;
    }
    void mergeList(ListNode* &head, ListNode* &slow, ListNode* &tail)
    {
        ListNode *p1 = head, *p2 = slow;
        while(p1 != NULL)
        {
            ListNode *p = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            tail = p2;
            p1 = p2->next;
            p2 = p;
        }
        if(p2) tail->next = p2;
    }
};
