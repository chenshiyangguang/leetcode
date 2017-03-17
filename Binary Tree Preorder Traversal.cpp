//Binary Tree Preorder Traversal
//author:guo chen
//date:2017/03/17
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//ʹ��O(1)�ռ临�Ӷ�,�ؼ����ڱ������ӽڵ��ʱ���������
//���ص����ڵ㣬ʹ�õ��������������ĸ���
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		TreeNode *pre = NULL;
		vector<int> result;
		while (root)
		{
			result.push_back(root->val);
			if (!root->left)
			{
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
					result.pop_back();
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
	vector<int> res = s.preorderTraversal(&a);
	for (auto i : res)
		cout << i << endl;
	return 0;
}