#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

/* Definition for a binary tree node. */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(root == nullptr) return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int n = q.size();
			vector<int> level;
			for(int i = 0; i < n; i++){
				TreeNode* node = q.front();
				q.pop();
				level.push_back(node->val);
				if(node->left != nullptr) q.push(node->left);
				if(node->right != nullptr) q.push(node->right);
			}
			ans.push_back(level);
		}
		return ans;

    }
};

void test(){
	vector<vector<int>> ans =  {{3}, {9, 20}, {15, 7}};
	TreeNode* nodo_a = new TreeNode(3);
	TreeNode* nodo_b = new TreeNode(9);
	TreeNode* nodo_c = new TreeNode(20);
	TreeNode* nodo_d = new TreeNode(15);
	TreeNode* nodo_e = new TreeNode(7);
	nodo_a->left = nodo_b;
	nodo_a->right = nodo_c;
	nodo_c->left = nodo_d;
	nodo_c->right = nodo_e;
	assert(Solution().levelOrder(nodo_a) == ans);
	
	ans =  {{1}};
	nodo_a = new TreeNode(1);
	assert(Solution().levelOrder(nodo_a) == ans);
}

int main(){
	test();
	return 0;
}
