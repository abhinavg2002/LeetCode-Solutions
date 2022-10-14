/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p=head, *q=NULL, *t=head;
        while(t->next){
            q=p;
            p=p->next;
            t=t->next;
            if(t->next)t=t->next;
        }
        if(q==NULL)return NULL;
        q->next=p->next;
        p->next=NULL;
        delete(p);
        return head;
    }
};