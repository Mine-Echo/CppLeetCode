
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
    ListNode* reverseList(ListNode* head) {
        ListNode* first=head;
        ListNode* second=head?head->next:nullptr;
        ListNode* tmp;
        if(head) head->next=nullptr;
        while(second!=nullptr){
            tmp=second->next;
            second->next=first;
            first=second;
            second=tmp;
        }
        return first;
    }
};