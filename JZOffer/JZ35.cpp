//复杂链表的深度拷贝
#include<map>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        //阿秀笔记上的解法，使用map
        if(pHead==nullptr)
            return nullptr;
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode* node=pHead;
        //深拷贝节点并插入到map中，与原链表节点形成一一对应关系
        while(node!=nullptr){
            RandomListNode* copy=new RandomListNode(node->label);
            m.insert({node,copy});
            node=node->next;
        }
        //设置next指针和random指针
        node=pHead;
        while(node!=nullptr){
            if(node->next!=nullptr)
                m.at(node)->next=m.at(node->next);
            if(node->random!=nullptr)
                m.at(node)->random=m.at(node->random);
            node=node->next;
        }
        return m.at(pHead);
    }
};