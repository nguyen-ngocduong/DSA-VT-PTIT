#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *createBinaryTree(vector<int> nodes){
    if (nodes.size() == 0) return NULL;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();
        // Xu ly node ben trai
        if (nodes[i] != -1) {
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        ++i;   
        // Xu ly node ben phai
        if (i < nodes.size() && nodes[i] != -1) {
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        ++i;
    }    
    return root;
}
int getDepth(TreeNode *root){
    int depth = 0;
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i =0; i<size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(i == 0){
                res.push_back(node->val);
            }
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        depth++;
    }
    return depth;
}
int main(){
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> nodes(n);
        for(int i = 0; i<n; i++){
            cin >> nodes[i];
        }
        TreeNode *root = createBinaryTree(nodes);
        cout << getDepth(root) << endl;
    }
    return 0;
}