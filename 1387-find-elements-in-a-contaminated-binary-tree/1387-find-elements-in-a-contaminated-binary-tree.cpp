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
class FindElements {
public:
    unordered_set<int>set;
        void unit(TreeNode*root,int t){
            if(root==NULL)return;
            root->val=t;
        set.emplace(root->val);
       unit(root->left,t*2+1);  
       unit(root->right,t*2+2);}
        FindElements(TreeNode* root) {
            int t=0;
            unit(root,t);
    }
    
    bool find(int target) {
       return set.count(target);
    }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */