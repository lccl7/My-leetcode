void deleteNode(ListNode* node)
{
    node->val = node->next->val;
    ListNode* p = node->next;
    node->next = p->next;
    delete p;
}
