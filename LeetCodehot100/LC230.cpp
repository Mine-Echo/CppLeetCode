
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void inOrder(TreeNode* root, int k, int& n, int& result){
        if(!root) return ;
        inOrder(root->left, k, n, result);
        if(++n == k){
            result = root->val;
            return;
        }
        inOrder(root->right, k, n, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int n=0, result;
        inOrder(root,k,n, result);
        return result;
    }
};