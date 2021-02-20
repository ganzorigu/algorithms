
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }        
        TreeNode *temp = nullptr;
        if (root->left != nullptr) {
            temp = invertTree(root->left);
            root->left = nullptr;
        }
        if (root->right != nullptr) {
            root->left = invertTree(root->right);
        }
        root->right = temp;
        return root;
    }
};