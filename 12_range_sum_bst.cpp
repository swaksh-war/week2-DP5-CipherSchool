#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* node, int& low, int& high, int& sum){
    if(!node) return;
    inorder(node->left, low, high, sum);
    if(node->val >= low && node->val <= high) sum += node->val;
    inorder(node->right, low, high, sum);
}

int rangeSumBST(TreeNode* root, int low, int high){
    int sum = 0;
    inorder(root, low, high, sum);
    return sum;
}

int main(){
    return 0;
}