#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *createBinaryTree(vector<int> nodes){
    if(nodes.size() == 0) return NULL;
    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < nodes.size()){
        TreeNode *node = q.front();
        q.pop();
        //Xu ly node ben trai
        if(nodes[i] != -1){
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        i++;
        //Xu ly node ben phai
        if(nodes[i] != -1 && i < nodes.size()){
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}
vector<int> rightSideView(TreeNode *root){//ham lay cac phan tu ben phai
    vector<int> result;
    if(root == NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(i == size - 1){
                result.push_back(node->val);
            }            
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return result;    
}
int main(){
    int t;cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> nodes(n);
        for(int i = 0; i<n; i++){
            cin >> nodes[i];
        }
        TreeNode *root = createBinaryTree(nodes);
        vector<int> result = rightSideView(root);
        for(int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}