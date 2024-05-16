//树的子结构

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};
class Solution {
public:
    bool HasSubtree(TreeNode* root1, TreeNode* root2) {
        //遍历
        if(root1==nullptr||root2==nullptr)
            return false;
        if(root1->val==root2->val)
            if(isMatch(root1, root2))
                return true;
        if(HasSubtree(root1->left, root2))
            return true;
        if(HasSubtree(root1->right, root2))
            return true;
        return false;
    }
    bool isMatch(TreeNode* root1, TreeNode* root2){
        //比较
        if(root2==nullptr)
            return true;
        if(root1==nullptr&&root2!=nullptr)
            return false;
        if(root1->val==root2->val){
            return isMatch(root1->left, root2->left)&&isMatch(root1->right, root2->right);
        }else{
            return false;
        }
    }
};
