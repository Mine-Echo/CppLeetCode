// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=new ListNode(0,head);//dummy
        ListNode* fast=slow, *node=slow;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        //删slow后面这个节点
        ListNode* del=slow->next;
        ListNode* next=del->next;
        slow->next=next;
        delete del;
        del=node;
        node=node->next;
        delete del;
        return node;
    }
};