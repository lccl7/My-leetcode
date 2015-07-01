/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //First we get the length of the list, then make the end point to the head
 //then we can move on length-k%length, this point is the end point for the last.
 //One thing should be paid attention to that if k is larger length of the list,
 //it does not mean the result will begin at the head, for example
 //{1, 2}, 3 the result is { 2, 1 }
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head;
        int length = 1;
        while(head->next != NULL)
        {
            head = head->next;
            ++length;
        }
        head->next = pstart->next;
        int n = length - k%length;
        while(n-- > 0) head = head->next;
        pstart->next = head->next;
        head->next = NULL;
        return pstart->next;
    }
};
