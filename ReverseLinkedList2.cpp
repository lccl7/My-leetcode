/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //The first method is just as below.
 //The second method is used two points point to where the reversed point begin(cur)
 //and the one before it(pre).
 //from the cur point we can point the next reversed point point to the one before it.
 //At last, we use pre to point to the last point.
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        
        if(head==NULL||head->next==NULL)
            return newhead->next;
            
        ListNode *startpoint = newhead;//startpoint指向需要开始reverse的前一个
        ListNode *node1 = NULL;//需要reverse到后面去的节点
        ListNode *node2 = NULL;//需要reverse到前面去的节点
        
        for (int i = 0; i < n; i++) {
            if (i < m-1){
                startpoint = startpoint->next;//找真正的startpoint
            } else if (i == m-1) {//开始第一轮
                node1 = startpoint->next;
                node2 = node1->next;
            }else {
                node1->next = node2->next;//node1交换到node2的后面
                node2->next = startpoint->next;//node2交换到最开始
                startpoint->next = node2;//node2作为新的点
                node2 = node1->next;//node2回归到node1的下一个，继续遍历
            }
        }
        return newhead->next;
    }
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pstart = new ListNode(0);
        pstart->next = head;
        ListNode *pre = pstart, *cur = head, *p1, *p2;
        int len = 1;
        while(len < m)
        {
            pre = cur;
            cur = cur->next;
            len++;
        }
        if(cur)  p1 = cur->next;
        if(p1) p2 = p1->next;
        while(len++ < n)
        {
            p1->next = cur;
            cur = p1;
            p1 = p2;
            if(p2) p2 = p2->next;
        }
        pre->next->next = p1;
        pre->next = cur;
        return pstart->next;
    }
};
