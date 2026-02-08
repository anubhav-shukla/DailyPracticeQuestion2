
class Solution {
    int height(TreeNode* root,bool &ans){
        if(root==NULL)
            return 0;
        int leftHeight=1+height(root->left,ans);
        int rightHeight=1+height(root->right,ans);
        if(abs(leftHeight-rightHeight)>1){
            ans=false;
            return 0;
        }
        return max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        height(root,ans);
        return ans;
    }
};
