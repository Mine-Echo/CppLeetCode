//从上往下打印二叉树
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            res.push_back(node->val);
            if(node->left!=nullptr)
                q.push(node->left);
            if(node->right!=nullptr)
                q.push(node->right);
        }
        return res;
    }
};
