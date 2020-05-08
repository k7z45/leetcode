/*
 * Slight modification to https://youtu.be/Arapvl6AiUI
 */
class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* parent, int node, int cur, int& depth)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == node)
        {
            depth = cur;
            return parent;
        }
        
        TreeNode* l = find(root->left, root, node, cur + 1, depth);
        if (l != nullptr)
        {
            return l;
        }
        TreeNode* r = find(root->right, root, node, cur + 1, depth);
        if (r != nullptr)
        {
            return r;
        }
        return nullptr;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = 0;
        TreeNode* p1 = find(root, nullptr, x, 0, d1);
        
        int d2 = 0;
        TreeNode* p2 = find(root, nullptr, y, 0, d2);
        return d1 == d2 && p1 != p2;
    }
};
