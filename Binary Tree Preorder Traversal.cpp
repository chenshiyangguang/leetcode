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
		TreeNode *pre = NULL;
		vector<int> result;
		while (root)
		{
			/*result.push_back(root->val);*/
			if (!root->left)
			{
				result.push_back(root->val);
				root = root->right;
			}
			else
			{
				pre = root->left;
				while (pre->right && pre->right != root)
					pre = pre->right;
				if (!pre->right)
				{
					pre->right = root;
					root = root->left;
				}
				else
				{
					result.push_back(root->val);
					pre->right = NULL;
					root = root->right;
				}
			}
		}
		return result;
	}
};
int main()
{
	TreeNode a(1), b(2), c(3), d(4), f(5);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &f;
	Solution s;
	vector<int> res = s.inorderTraversal(&a);
	for (auto i : res)
		cout << i << endl;
	return 0;
}