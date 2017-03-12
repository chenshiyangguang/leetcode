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

//ʹ��O(1)�ռ临�Ӷ�,�ؼ����ڱ������ӽڵ��ʱ���������
//���ص����ڵ㣬ʹ�õ��������������ĸ���
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		vector<int > result;
		while (cur != NULL)
		{
			//1. ����ڵ�Ϊ��ʱ������ǰ�ڵ���������Һ�����Ϊ��ǰ�ڵ�
			if (cur->left == NULL)
			{
				result.push_back(cur->val);
				cur = cur->right;
			}
			//2.����ڵ㲻Ϊ��ʱ
			else
			{
				//ǰ���ڵ�
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur)
					pre = pre->right;
				//2.1ǰ���ڵ��Һ���Ϊ��
				if (pre->right == NULL)
				{
					pre->right = cur;
					cur = cur->left;
				}
				//2.2ǰ���ڵ��Һ���Ϊ��ǰ�ڵ㣬��ԭ
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