
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sum;
    int sumOfLeftLeaves(TreeNode *root)
    {
        sum = 0;
        if (root != nullptr)
        {
            traversal(root);
        }
        return sum;
    }
    void traversal(TreeNode *root)
    {
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            sum += root->left->val;
        }
        if (root->left != nullptr)
        {
            traversal(root->left);
        }
        if (root->right != nullptr)
        {
            traversal(root->right);
        }
        return;
    }
};

// solution from discussion
// class Solution {
//     public int sumOfLeftLeaves(TreeNode root) {
//         if(root == null){
//             return 0;
//         }
//         if(root.left != null && root.left.left == null && root.left.right == null) {
//             return root.left.val + sumOfLeftLeaves(root.right);
//         }
//         return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
//     }
// }
