/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // A recursive method(52s) and non-recursive method(16s).
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return issym(root->left, root->right);
    }
    
    bool issym(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        return (p->val == q->val) && issym(p->left, q->right) && issym(p->right, q->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        if(!root->left && !root->right) return true;
        if(root->left && root->right == NULL) return false;
        if(root->right && root->left == NULL) return false;
        list<TreeNode*> list1, list2;
        list1.push_back(root->left); list2.push_back(root->right);
        while(!list1.empty() && !list2.empty())
        {
            TreeNode *l1 = *list1.begin(); list1.pop_front();
            TreeNode *l2 = *list2.begin(); list2.pop_front();
            if(l1->val != l2->val) return false;
            if((l1->left == NULL && l2->right) || (l1->left && l2->right == NULL)) return false;
            if((l1->right && l2->left == NULL) || (l1->right == NULL && l2->left)) return false;
            if((l1->left && l2->right)) 
            {
                list1.push_back(l1->left); list2.push_back(l2->right);
            }
            if((l1->right && l2->left)) 
            {
                list1.push_back(l1->right); list2.push_back(l2->left);
            }
        }
        return true;
    }
};
