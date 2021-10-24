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
        if(n == 0) return nullptr;//特判
        return MSort(lists, 0, n-1);
        
    }
private:
    //合并lists中下标从low开始到high结束的链表序列
    //分治思想（自底向上）
    //处理边界：当只有一个链表（low==high）时，直接返回
    //相似子问题：将low到high的链表序列分为两部分：low~mid，mid+1~high，分别将这两部分合并
    //本层逻辑：将合并好的两部分链表再合二为一（调用mergeTwoLists）
    ListNode* MSort(vector<ListNode*>& lists, int low, int high) {
        if (low == high) return lists[low];
        ListNode* l1=nullptr, * l2=nullptr, * ans=nullptr;
        int mid = (low+high) / 2;
        l1 = MSort(lists, low, mid);
        l2 = MSort(lists, mid+1, high);
        ans = mergeTwoLists(l1, l2);
        return ans;
    }
    //合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2, *p3;
        ListNode* head = new ListNode();//结果链的头结点（保护结点）
        p3 = head;//p3指向结果链的最后一个结点
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
        //处理剩余的尾部
        if (p1 != nullptr)
            p3->next = p1;
        else
            p3->next = p2;
        return head->next;
    }
};