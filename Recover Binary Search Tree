class Solution {
public:
    
    TreeNode *p1, *p2, *pre;
    
    void recoverTree(TreeNode *root) {
        pre = NULL; 
        p1 = NULL;
        p2 = NULL;
        inorder(root);
        if(p1 != NULL && p2 != NULL)
        {
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
    }
    void inorder(TreeNode *root)
    {
        if(root == NULL) return;
        inorder(root->left);
        if(pre == NULL)
            pre = root;
        else 
        {
            if(root->val < pre->val)
            {
                if(p1 == NULL)
                    p1 = pre;
                p2 = root;
            }
            
            pre = root;
        }
        inorder(root->right);
    }
};
