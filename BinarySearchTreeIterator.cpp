/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<int> stree;
    BSTIterator(TreeNode *root) {
        getInOrder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stree.empty();
    }

    /** @return the next smallest number */
    int next() {
        int i = stree.top();
        stree.pop();
        return i;
    }
    void getInOrder(TreeNode *root)
    {
        if(NULL != root)
        {
            getInOrder(root->right);
            stree.push(root->val);
            getInOrder(root->left);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
