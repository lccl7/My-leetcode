ListNode* reverseKGroup(ListNode* head, int k)
{
    if(k <= 1 || !head || !head->next) return head;
    ListNode Dummy(-1);
    Dummy.next = head;
    ListNode *beginK = &Dummy, *endK = &Dummy;

    while(true)
    {
        for(int i = 0; i < k && endK; i++)
            endK = endK->next;
        if(!endK) break;

        ListNode *cur = beginK->next;//When started, beginK->next always points to the head of the k-group
        for(int i = 0; i < k-1; i++) // each time reverse one node, and do k-1 iterations
        {
            ListNode *tmp = cur->next;//tmp is a temporary point that next to the front,which we reverse to the front
            cur->next = tmp->next;
            tmp->next = beginK->next;//begink->next which now is the front becomes the second one
            beginK->next = tmp;     // Then begink->next retrieve to the first one
        }
        beginK = cur;
        endK = cur;
    }
    return Dummy.next;
}

//A recursive way
ListNode* reverseKGroup(ListNode* head, int k)
{
    return reverseK(head, k, getlength(head));
}

ListNode* reverseK(ListNode* head, int k, int len)
{
    if(k == 1 || k > len || !head) return head;
    int i = 2;
    ListNode* cur = head->next;
    ListNode* pre = head;
    head->next = NULL;
    ListNode* Dummy = head;
    while(i <= k)
    {
        head = cur;
        cur = cur->next;
        head->next = pre;
        pre = head;
        head = cur;
        i++;
    }
    Dummy->next = reverseK(head, k, len-k);
    return pre;
}

int getlength(ListNode* head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}
