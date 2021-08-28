/*

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Solution.

Maintain a queue.
For each level, pop the elements in that level and kepp inserting the child elements. 
When the loop iterator reaches the count of nodes at that level, push the element to the result vector 
because that's the rightmost elemnt of that level.


*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (NULL == root) {
            return res;
        }
        queue<TreeNode *> q;
        
        //Push the root initially
        q.push(root);
        while (!q.empty()) {
            //Loop though all the nodes at each level and insert the last entry because that is the right  side view.
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (i == size -1) {res.push_back(node->val);}
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
            
    } 
};
