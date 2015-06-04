//pointer to the one before link one by one.
//till the last.
ListNode* reverseList(ListNode* head)
{
    ListNode* last = NULL;
    while(head)
    {
        ListNode* next = head->next;
        head->next = last;
        last = head;
        head = next;
    }
    return last;
}
