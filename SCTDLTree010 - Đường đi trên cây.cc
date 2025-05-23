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
        if(nodes[i] != -1){
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        i++;
        if(nodes[i] != -1 && i < nodes.size()) {
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}
void findPath(TreeNode *node, vector<int>& path, vector<vector<int>>& allPaths){
    if(!node) return;
    path.push_back(node->val);
    if(!node->left && !node->right) allPaths.push_back(path);
    else{
        findPath(node->left, path, allPaths);
        findPath(node->right, path, allPaths);
    }
    path.pop_back();//backtrack;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nodes(n);
        for(int  i = 0; i<n; i++) cin >> nodes[i];
        TreeNode *root = createBinaryTree(nodes);
        if(!root) {
            cout << '0\n';
        }
        vector<int> path;
        vector<vector<int>> allPaths;
        findPath(root, path, allPaths);
        if(allPaths.empty()){
            cout << '0\n';
        }
        else{
            for(auto &path : allPaths){
                for (int i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << "->";
                }
                cout << endl;
            }
        }
    }
    return 0;
}