// Definition for a binary tree node.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;         //A temporary vector to store elments of each level.
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty()){
            int qsize= q.size();
            for(int i=0;i<qsize;i++){           //No. of elements in queue will be equal to no. of element on same level.
                TreeNode* curr=q.front();
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                q.pop();
            }
            ans.push_back(temp);            //Pushing elements of same level into the ans vector
            temp.clear();
        }
        return ans;
    }
};
