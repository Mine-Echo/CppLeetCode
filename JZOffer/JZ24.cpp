//反转链表
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // write code here
        //头插法
        ListNode* newHead=nullptr;
        while(head!=nullptr){
            ListNode* node=head;
            head=head->next;
            node->next=newHead;
            newHead=node;
        }
        return newHead;
        //三指针法已经用java实现了
    }
};