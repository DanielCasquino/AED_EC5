#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
using namespace std;


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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
    }
};

void test(){
	
	TreeNode* nodo_a = new TreeNode(2);
	TreeNode* nodo_b = new TreeNode(1);
	
	TreeNode* nodo_c = new TreeNode(3);
	TreeNode* nodo_d = new TreeNode(2);
	TreeNode* nodo_e = new TreeNode(5);
	
	TreeNode* nodo_f = new TreeNode(5);
	TreeNode* nodo_g = new TreeNode(4);
	
	nodo_a->left = nodo_b;
	
	nodo_c->left = nodo_d;
	nodo_c->right = nodo_e;
	
	nodo_f->left = nodo_g;
	
	vector<TreeNode*> trees = {nodo_c, nodo_f};

	TreeNode* ans = Solution().canMerge(trees);
	assert(ans == nodo_c);
}

int main(){
	test();
	return 0;
}
