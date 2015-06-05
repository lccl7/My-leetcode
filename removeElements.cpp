//Be careful that the head may be NULL

ListNode* removeElements(ListNode* head, int val)
{
    while(head && head->val == val)
        head = head->val;
    if(head == NULL) return NULL;
    ListNode* pre = head, *p = pre->next;
    while(p)
    {
        if(p->val == val)
        {
            pre->next = p->next;
            p = p->next;
        }
        else {
            pre = pre->next;
            p = p->next;
        }
    }
    return head;
}
