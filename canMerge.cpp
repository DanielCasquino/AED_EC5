#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
using namespace std;

/*
INTEGRANTES:

->Daniel Casquino

->Alexis Raza

->Gabriel Blanco*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode *canMerge(vector<TreeNode *> &trees)
	{
		TreeNode *bigTree = nullptr;
		for (int i = 0; i < trees.size(); ++i)
		{
			for (int j = 0; j < trees.size(); ++j)
			{
				if (j != i)
				{
					// guardar i,j
					auto first = trees[i];
					auto second = trees[j];
					std::unordered_map<int, int> map{};
					std::vector<TreeNode *> toInsert{};
					// comparar left y right i con raiz j
					if (second->val == first->right->val)
					{
						toInsert.push_back(first);
						toInsert.push_back(first->left);
						toInsert.push_back(second->left);
						toInsert.push_back(second->right);
						for (TreeNode *node : toInsert)
						{
							if (node)
							{
								++map[node->val];
								if (map[node->val] > 1)
								{
									goto noMatchRight; // Algun valor se repite n > 1 veces
								}
							}
						}
						first->right = second;
						trees.erase(std::next(trees.begin(), j));
						trees.shrink_to_fit();
						bigTree = first;
					noMatchRight:
					}
					else if (second->val == first->left->val)
					{
						toInsert.push_back(first);
						toInsert.push_back(first->right);
						toInsert.push_back(second->left);
						toInsert.push_back(second->right);
						for (TreeNode *node : toInsert)
						{
							if (node)
							{
								++map[node->val];
								if (map[node->val] > 1)
								{
									goto noMatchLeft; // Algun valor se repite n > 1 veces
								}
							}
						}
						first->left = second;
						trees.erase(std::next(trees.begin(), j));
						trees.shrink_to_fit();
						bigTree = first;
					noMatchLeft:
					}
				}
			}
		}
		return bigTree;
	}
};

void test()
{

	TreeNode *nodo_a = new TreeNode(2);
	TreeNode *nodo_b = new TreeNode(1);

	TreeNode *nodo_c = new TreeNode(3);
	TreeNode *nodo_d = new TreeNode(2);
	TreeNode *nodo_e = new TreeNode(5);

	TreeNode *nodo_f = new TreeNode(5);
	TreeNode *nodo_g = new TreeNode(4);

	nodo_a->left = nodo_b;

	nodo_c->left = nodo_d;
	nodo_c->right = nodo_e;

	nodo_f->left = nodo_g;

	vector<TreeNode *> trees = {nodo_c, nodo_f};

	TreeNode *ans = Solution().canMerge(trees);
	assert(ans == nodo_c);
}

int main()
{
	test();
	return 0;
}
