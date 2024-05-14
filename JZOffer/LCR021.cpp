//删除链表中倒数第n个节点
//Definition for singly-linked list.
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
        if(n==0)
            return nullptr;
        ListNode* front=head;
        ListNode* back=head;
        while(front->next!=nullptr){
            front=front->next;
            if(n<=0){
                back=back->next;
            }
            n--;
        }
        //删除head
        if(n==1){
            front=head->next;
            delete head;
            return front;
        }
        //超出界限
        if(n>1){
            return nullptr;
        }
        //删除back后面一个指针
        front=back->next;
        back->next=back->next->next;
        delete front;
        return head;
    }
};