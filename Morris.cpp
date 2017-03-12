//leetcode 94 Binary Tree Inorder Traversal
//author:guo chen
//date:2017/03/12
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//使用O(1)空间复杂度,关键在于遍历到子节点的时候如何重新
//返回到父节点，使用到了线索二叉树的概念
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		vector<int > result;
		while (cur != NULL)
		{
			//1. 当左节点为空时，将当前节点输出，将右孩子做为当前节点
			if (cur->left == NULL)
			{
				result.push_back(cur->val);
				cur = cur->right;
			}
			//2.当左节点不为空时
			else
			{
				//前驱节点
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur)
					pre = pre->right;
				//2.1前驱节点右孩子为空
				if (pre->right == NULL)
				{
					pre->right = cur;
					cur = cur->left;
				}
				//2.2前驱节点右孩子为当前节点，复原
				else
				{
					pre->right = NULL;
					result.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return result;
	}
};
int main()
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right = &b;
	b.left = &c;
	Solution s;
	vector<int> result = s.inorderTraversal(&a);
	for (auto i : result)
		cout << i << endl;
	return 0;
}