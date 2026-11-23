
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 我写的，用了一个辅助函数，返回值是一个三元组，分别表示当前子树是否包含p，是否包含q，以及当前子树的最近公共祖先
// class Solution {
//     TreeNode* lowestCommonAncestorCore(TreeNode* root, TreeNode* p, TreeNode* q, bool& has_p, bool& has_q){
//         if(!root) return nullptr;
//         bool has_p_left=false,has_q_left=false;
//         TreeNode* left=lowestCommonAncestorCore(root->left,p,q,has_p_left,has_q_left);
//         if(left) return left;
//         bool has_p_right=false,has_q_right=false;
//         TreeNode* right=lowestCommonAncestorCore(root->right,p,q,has_p_right,has_q_right);
//         if(right) return right;
//         // 当前节点
//         has_p=has_p_left||has_p_right||root==p;
//         has_q=has_q_left||has_q_right||root==q;
//         if(has_p&&has_q) return root;
//         return nullptr;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         bool has_p=false,has_q=false;
//         return lowestCommonAncestorCore(root,p,q,has_p,has_q);
//     }
// };

// 题解，更简洁的写法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root; // 找到 p 或 q 就不往下递归了，原因见上面答疑
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) { // 左右都找到
            return root; // 当前节点是最近公共祖先
        }
        // 如果只有左子树找到，就返回左子树的返回值
        // 如果只有右子树找到，就返回右子树的返回值
        // 如果左右子树都没有找到，就返回 nullptr（注意此时 right = nullptr）
        return left ? left : right;
    }
};
