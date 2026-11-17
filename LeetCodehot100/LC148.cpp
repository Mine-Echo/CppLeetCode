#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// bool cmp(ListNode* a, ListNode* b){
//     return a->val<b->val;
// }

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<ListNode*> nodes;
//         while(head){
//             nodes.push_back(head);
//             head = head->next;
//         }
//         sort(nodes.begin(),nodes.end(),cmp);
//         ListNode dummy=ListNode(0),*last=&dummy;
//         for(auto node:nodes){
//             last->next=node;
//             last=node;
//         }
//         last->next=nullptr;
//         last=dummy.next;
//         return last;
//     }
// };


class Solution {
    ListNode* middleNode(ListNode* head){
        ListNode* pre=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // 用哨兵节点简化代码逻辑
        ListNode* cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            } else { // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* head2=middleNode(head);
        head=sortList(head);
        head2=sortList(head2);
        return mergeTwoLists(head, head2);
    }
};