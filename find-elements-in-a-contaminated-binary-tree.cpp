
class FindElements
{
private:
    unordered_set<int> values;

    // Step 1: Recover the tree using DFS
    void recover(TreeNode* node, int val)
    {
        if (!node)
        {
            return;
        } 
        
        node->val = val;
        values.insert(val);
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }

public:
    // Step 2: Constructor to recover tree
    FindElements(TreeNode* root)
    {
        recover(root, 0);
    }

    // Step 3: Find function (O(1) lookup)
    bool find(int target)
    {
        return values.find(target) != values.end();
    }
};

