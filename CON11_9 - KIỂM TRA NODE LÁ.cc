#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main(){
    int t; cin >> t;
    while (t--)
    {
        int n,u,v;
        char x;
        cin >> n;
        TreeNode *root = nullptr;
        map<int, TreeNode*> nodes;
        while (n--)
        {
            cin >> u >> v >> x;
            if(!nodes[u]) nodes[u] = new TreeNode(u);
            if(!nodes[v]) nodes[v] = new TreeNode(v);
            if(!root) root = nodes[u];
            if(x == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
        }
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        set<int> leaf_levels;
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            // Neu la node la
            if(!node->left && !node->right) leaf_levels.insert(level);
            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});
        }
        if(leaf_levels.size() == 1) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}