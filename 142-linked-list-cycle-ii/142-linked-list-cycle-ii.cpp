/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto *h=head;
        map<ListNode*, int> m;
        while(h){
            if(m.count(h))return h;
            m[h]++;
            h=h->next;
        }
        return nullptr;
    }
};