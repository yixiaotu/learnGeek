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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;//����
        return MSort(lists, 0, n-1);
        
    }
private:
    //�ϲ�lists���±��low��ʼ��high��������������
    //����˼�루�Ե����ϣ�
    //����߽磺��ֻ��һ������low==high��ʱ��ֱ�ӷ���
    //���������⣺��low��high���������з�Ϊ�����֣�low~mid��mid+1~high���ֱ��������ֺϲ�
    //�����߼������ϲ��õ������������ٺ϶�Ϊһ������mergeTwoLists��
    ListNode* MSort(vector<ListNode*>& lists, int low, int high) {
        if (low == high) return lists[low];
        ListNode* l1=nullptr, * l2=nullptr, * ans=nullptr;
        int mid = (low+high) / 2;
        l1 = MSort(lists, low, mid);
        l2 = MSort(lists, mid+1, high);
        ans = mergeTwoLists(l1, l2);
        return ans;
    }
    //�ϲ�������������
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2, *p3;
        ListNode* head = new ListNode();//�������ͷ��㣨������㣩
        p3 = head;//p3ָ�����������һ�����
        if (p1 == nullptr) return p2;
        if (p2 == nullptr) return p1;
        while(p1 != nullptr && p2 != nullptr)
            if (p1->val <= p2->val) {            
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
            } else {             
                p3->next = p2;
                p3 = p2;
                p2 = p2->next;
            }
        //����ʣ���β��
        if (p1 != nullptr)
            p3->next = p1;
        else
            p3->next = p2;
        return head->next;
    }
};