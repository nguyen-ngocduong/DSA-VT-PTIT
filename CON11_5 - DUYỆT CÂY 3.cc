#include<bits/stdc++.h>
// duyet cay theo BFS 
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(){
    int t; cin >> t;
    while(t--){
        int n,u,v;
        char x;
        cin >> n;
        map<int, TreeNode*> nodes;
        TreeNode *root = nullptr;
        while (n--)
        {
            cin >> u >> v >> x;
            if(!nodes[u]) nodes[u] = new TreeNode(u); //Kiểm tra nếu chưa tạo node u thì tạo mới node u
            if(!nodes[v]) nodes[v] = new TreeNode(v);
            if(!root) root = nodes[u];
            if(x == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
    return 0;
}