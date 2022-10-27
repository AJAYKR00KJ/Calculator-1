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
    vector<TreeNode*> ans;
    unordered_map<string,int> mp;
    string find(TreeNode* root) {
        if(root==NULL) return "#";
        string lft = find(root->left);
        string rgt = find(root->right);
        
        string curr= '('+lft+')'+to_string(root->val)+'('+rgt+')'; 
        if(mp[curr]==1) ans.push_back(root);
        mp[curr]++;
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        find(root);
        return ans;
    }
};

//   0  0
//  /    \
// 0      0
      
//    ((#)0(#))0(#)   (#)0((#)0(#))   
