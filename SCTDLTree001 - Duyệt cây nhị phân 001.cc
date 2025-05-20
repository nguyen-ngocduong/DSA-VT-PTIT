#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* createBinaryTree(vector<int> &nums){
    if(nums.size() == 0) return NULL;
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < nums.size()){
        TreeNode* node = q.front();
        q.pop();
        // Xử lý nút con bên trái
        if(nums[i] != -1){
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        // Xử lý nút con bên phải
        if (i < nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}
// Hàm in ra thứ tự cấp độ của các giá trị nút trong cây nhị phân
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        TreeNode* root = createBinaryTree(nums);
        levelOrderTraversal(root);
    }

    return 0;
}
