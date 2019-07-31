/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TreeNode* toBST(ListNode **head, int n){
    
    if(n<=0){
        return NULL;
        //leaf nodes
    }
    
    TreeNode* leftnode = toBST(head,n/2);
    
    TreeNode* root = new TreeNode((*head)->val);    //definition of root must lie after leftnode
    root->left = leftnode;                          //this is kind of inorder build up
    
    (*head) = (*head)->next;                        //changing head with reference
    
    TreeNode* rightnode = toBST(head, n- (n/2 + 1));    
    //right number of nodes = totalnodes - leftnodes - rootnode
    root->right = rightnode;
    
    return root;
    
} 
 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n=0;
    ListNode* t = A;
    while(t!=NULL)
    {
        n++;
        t = t->next;
    }
    
    return toBST(&A,n);
}
