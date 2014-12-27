/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //The hardest part is how to deal with the sum when you go to the next level
 //I get some idea from this, http://blog.csdn.net/kenden23/article/details/14100851
 //and use the sum as a parameter.(the runtime of the three are the same (8ms))
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumTree(root, 0);
    }
    int sumTree(TreeNode *root, int s)
    {
        if(root == NULL) return s;
        else if(root->left== NULL && root->right == NULL) return s + root->val;
        else if(root->left && root->right == NULL) return sumTree(root->left, (s+root->val)*10);
        else if(root->right && root->left == NULL) return sumTree(root->right, (s+root->val)*10);
        else if(root->left && root->right) return sumTree(root->left, (s+root->val)*10)+sumTree(root->right, (s+root->val)*10);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumup(root, sum);  
        return sum; 
    }
    void sumup(TreeNode *r, int &sum, int path_sum = 0)  
    {  
        if (!r) return;  
        int t = path_sum*10 + r->val;  
        sumup(r->left, sum, t);  
        sumup(r->right, sum, t);  
        if (!r->left && !r->right) sum += t;  
    }  
};

    return sumup(root);  
    }  
    int sumup(TreeNode *r, int path = 0)  
    {  
        if (!r) return 0;  
        if (!r->left && ! r->right) return 10*path+r->val;  
        return sumup(r->left, 10*path+r->val)+sumup(r->right, 10*path+r->val);  
    }  
