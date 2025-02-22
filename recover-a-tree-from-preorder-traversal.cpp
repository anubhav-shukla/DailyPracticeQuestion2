class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0;
        
        while (i < traversal.size()) {
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            int num = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(num);

            while (st.size() > depth) {
                st.pop();
            }

            if (!st.empty()) {
                if (!st.top()->left) {
                    st.top()->left = node;
                } else {
                    st.top()->right = node;
                }
            }

            st.push(node);
        }

        return st.top();
    }
};
