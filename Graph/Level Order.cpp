/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<vector<int> > sol;
    if(A==NULL) return sol;
    
    queue<pair<TreeNode*,int> > Q;
    Q.push(make_pair(A,0));
    
    while(!Q.empty()){
        TreeNode* T = Q.front().first;
        int level = Q.front().second;
        Q.pop();
        
        if(sol.size()==level)
            sol.push_back(vector<int>{});
            
        sol[level].push_back(T->val);
        
        if(T->left)
            Q.push(make_pair(T->left,level+1));
        if(T->right)
            Q.push(make_pair(T->right,level+1));
        
    }
    
    return sol;
}
