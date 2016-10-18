//
//  main.cpp
//  leetcode257
//
//  Created by zencher on 16/6/24.
//  Copyright © 2016年 zencher. All rights reserved.
//
//  Given a binary tree, return all root-to-leaf paths.
//
//  For example, given the following binary tree:
//
//       1
//      / \
//     2   3
//      \
//       5
//
//  All root-to-leaf paths are:
//
//  ["1->2->5", "1->3"]

#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ret;
        
        if (root == NULL)
            return ret;
        
        vector<TreeNode*> path;
        
        TreeNode * tmpNode = root, *plast = NULL;
        
        while (tmpNode || !path.empty()) {
            while(tmpNode)
            {
                path.push_back(tmpNode);
                tmpNode = tmpNode->left;
            }
            tmpNode = path.back();
            if (tmpNode->left == NULL && tmpNode->right == NULL)
            {
                string strpath;
                strpath += to_string(path[0]->val);
                for (int i = 1; i < path.size(); ++i)
                {
                    strpath += "->";
                    strpath += to_string(path[i]->val);
                }
                ret.push_back(strpath);
            }
            if (tmpNode->right != NULL && tmpNode->right != plast)
                tmpNode = tmpNode->right;
            else
            {
                plast = tmpNode;
                path.pop_back();
                tmpNode = NULL;
            }
        }
        
        return ret;
    }
};

#include <iostream>

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    
    vector<string> ret;
    Solution s;
    ret = s.binaryTreePaths(root);
    
    return 0;
}
