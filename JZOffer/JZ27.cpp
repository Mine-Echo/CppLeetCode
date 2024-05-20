#include<queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
	
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
		//使用队列，递归版本用java实现
		if(pRoot==nullptr) return nullptr;
		queue<TreeNode*> q;
		q.push(pRoot);
		while(!q.empty()){
			TreeNode* node=q.front();
			q.pop();
			if(node!=nullptr){
				q.push(node->left);
				q.push(node->right);
				//swap
				TreeNode* tmp=node->left;
				node->left=node->right;
				node->right=tmp;
			}
		}
		return pRoot;
    }
};