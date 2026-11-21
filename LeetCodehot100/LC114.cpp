
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
    TreeNode* flattenCore(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* first_tail,*second_tail,*left=root->left,*right=root->right;
        root->left=nullptr;
        if(left){
            first_tail = flattenCore(left);
            root->right=left;
        }else{
            first_tail = root;
        }
        if(right){
            second_tail = flattenCore(right);
            first_tail->right=right;
        }else{
            second_tail = first_tail;
        }
        return second_tail;
    }
public:
    void flatten(TreeNode* root) {
        flattenCore(root);
    }
};