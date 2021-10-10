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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1,*p2=l2,*p3;
        ListNode* head = new ListNode();
        p3 = head;
        if(p1 == nullptr)
            return p2;
        if(p2 == nullptr)
            return p1;
        while(p1!=nullptr && p2!=nullptr)
        {
            if(p1->val <= p2->val)
            {            
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
            }
            else
            {             
                p3->next = p2;
                p3 = p2;
                p2 = p2->next;
            }
        }
        if(p1!=nullptr)
        {
            p3->next = p1;
        }
        else
        {
            p3->next = p2;
        }
        return head->next;
    }
};