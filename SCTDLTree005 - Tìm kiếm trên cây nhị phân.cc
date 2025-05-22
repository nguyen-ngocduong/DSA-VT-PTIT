#include<bits/stdc++.h>
using namespace std;
// 2/10 test
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
        //Xu ly node trai
        if(nodes[i] != -1){
            node->left = new TreeNode(nodes[i]);
            q.push(node->left);
        }
        ++i;
        //Xu ly node phai
        if(nodes[i] != -1 && i < nodes.size()){
            node->right = new TreeNode(nodes[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}
pair<int, int> dfs(TreeNode* root) {
    if (!root) return {0, 0};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int rob = root->val + left.second + right.second;
    int not_rob = max(left.first, left.second) + max(right.first, right.second);

    return {rob, not_rob};
}

int rob(TreeNode* root) {
    auto result = dfs(root);
    return max(result.first, result.second);
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nodes(n);
        for(int i =0 ; i<n; i++){
            cin >> nodes[i];
        }
        TreeNode *root = createBinaryTree(nodes);
        cout << rob(root) << endl;
    }
    return 0;
}