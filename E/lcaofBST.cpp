/*

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Well, remember to take advantage of the property of binary search trees, which is, node -> left -> val < node -> val < node -> right -> val. Moreover, both p and q will be the descendants of the root of the subtree that contains both of them. And the root with the largest depth is just the lowest common ancestor. This idea can be turned into the following simple recursive code.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        //See if we need to go to the left tree
        if(p->val < root->val && q->val < root->val)
            root = lowestCommonAncestor(root->left, p , q);
        //See if we need to go to the right tree
        if (p->val > root->val && q->val > root->val)
            root = lowestCommonAncestor(root->right, p , q);
        //this is the common ancestor
        return root;
    }
};
