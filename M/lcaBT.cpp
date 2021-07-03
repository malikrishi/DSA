/**
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * //Two Solutions :
 * Solution 1 : 
 * 1. Find the path from route to each node and keep them in teo vector p1 & p2
 * 2. Travers both the path one by one untile you find a not common node.
 * 3. Result is p1[idx -1]
 * 
 * Time Complexity : Traverse the binary tree twice O(n), Space complexity O(n)
 *
 * Solution 2 : 
 * Use recursion :
 *  Base case : Check if root is NULL return NULL
 *              Check if root is either of the two, then return true
 *  Call recursively for left and right subtree. If the both the trees return true means we have one on the left subtree
 *  and other on the right subtree whick menas this isthe lca.
 *  if either of them is NULL , means we have the nodes in the left or the right subtree whick also means that this node is the LCA.
 *
 *
 *
 *
 *

 */
class Solution {
public:
    bool findPath(TreeNode *root, TreeNode *p, vector<TreeNode *> &res) {
        if(root == nullptr) return false;
        
        res.push_back(root);
        if (root->val == p->val) return true;
        if(findPath(root->left, p, res) == false && findPath(root->right, p, res) == false) {
            res.pop_back();
        } else {
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Solution 1
        if (root==nullptr) return nullptr;
        vector<TreeNode *> p1;
        vector<TreeNode *> p2;
        findPath(root, p, p1);
        //for(int i = 0; i < p1.size(); i++) cout << "P1 " << p1[i]->val << endl;
        findPath(root, q, p2);
        //for(int i = 0; i < p2.size(); i++) cout << "P2 " << p2[i]->val << endl;
        int p1Len = p1.size();
        int p2Len = p2.size();
        int min = (p1Len < p2Len) ? p1Len : p2Len;
        int i ;
        for (i = 0 ; i < min; i++) {
            if (p1[i] != p2[i]) break;
        }
        return p1[i-1];        
    }
    
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root is null, return  
        if(!root) return nullptr;
        
        // case1: test if root equals p or q
        if(root == p || root == q ) return root;
        
        // case2 & 3: try to find LCA in left/right subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // if left is not null, case1 is fulfilled in next recursion, which means p or q exactly exists in left subtree
        // if both left and right are not null, p and q exists in left/right subtree separatedly,
        // so root is the LCA.
        if(left && right ) return root;
        
        
        // if only left is not null, p/q both exist in left subtree. so return left.
        // the same for the right subtree case.
        return left?left:right;
    }
};
