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

void inorder(TreeNode* root, vector<int>&inorderVal){
    if(root == NULL){
        return;
    }
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->val);
    inorder(root->right, inorderVal);
}


TreeNode* inorderToBST(int s, int e, vector<int> &inorderVal){
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    TreeNode* temp = new TreeNode(inorderVal[mid]);
    temp->left = inorderToBST(s, mid-1, inorderVal);
    temp->right = inorderToBST(mid+1, e, inorderVal);
    return temp;
}


TreeNode* balancedBST(TreeNode* root){
    vector<int> inorderVal;
    inorder(root, inorderVal);
    return inorderToBST(0, inorderVal.size()-1, inorderVal);
}

int main(){
    return 0;
}