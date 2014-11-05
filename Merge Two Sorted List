One solution: Just use pointer:
   ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head = new ListNode(0);
        ListNode *l = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                l->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                l->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            l = l->next;
        }
        if(l1 != NULL)
        {
            l->next = l1;
        }
        if(l2 != NULL)
        {
            l->next = l2;
        }
        return head->next;
    }
Another with the help of the container List:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        list<int> lint1, lint2;
        while(l1) 
        {
            lint1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) 
        {
            lint2.push_back(l2->val);
            l2 = l2->next;
        }
        lint1.merge(lint2);
        ListNode* head = new ListNode(0);
        ListNode *p = head;
        for(std::list<int>::iterator i = lint1.begin(); i != lint1.end(); ++i)
        {
            p->next = new ListNode(*i);
            p = p->next;
        }
        return head->next;
    }
