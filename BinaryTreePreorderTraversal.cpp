/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vi;
       // if(root == NULL) return vi;
        stack<TreeNode*> st;
        if(root == NULL) return vi;
        st.push(root);
        while(!st.empty())
        {
            root = st.top();
            vi.push_back(st.top()->val);
            st.pop();
            if(root->right != NULL)
                st.push(root->right);
            if(root->left != NULL)
                st.push(root->left);
        }
        return vi;
        }
};
