
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {

//     bool isValidBSTCore(TreeNode* root, long left, long right){
//         if(!root) return true;
//         return left<root->val && root->val<right && isValidBSTCore(root->left, left, root->val) && isValidBSTCore(root->right, root->val, right);
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBSTCore(root, LONG_MIN, LONG_MAX);
//     }
// };

#include <algorithm>
using namespace std;

class Solution {
    pair<long, long> isValidBSTCore(TreeNode* root){
        if(!root) return {LONG_MAX, LONG_MIN};
        auto left=isValidBSTCore(root->left);
        if(left.second>=root->val) return {LONG_MIN, LONG_MAX};
        auto right=isValidBSTCore(root->right);
        if(root->val>=right.first){
            return {LONG_MIN, LONG_MAX};
        }
        return {min((long)root->val, left.first), max((long)root->val, right.second)};
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTCore(root).first != LONG_MIN;
    }
};