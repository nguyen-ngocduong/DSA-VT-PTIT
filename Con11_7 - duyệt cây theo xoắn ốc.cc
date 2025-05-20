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
        while(n--){
            cin >> u >> v >> x;
            if(!nodes[u]) nodes[u] = new TreeNode(u);
            if(!nodes[v]) nodes[v] = new TreeNode(v);
            if(!root) root = nodes[u];
            if(x == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            cout << node->val << " ";
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        cout << endl;
    }
    return 0;
}