//从尾到头打印链表
#include<vector>
#include<algorithm>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while(head!=nullptr){
            res.push_back(head->val);
            head=head->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
