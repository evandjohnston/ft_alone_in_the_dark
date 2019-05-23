#include <stdlib.h>

	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

	void perimeter(struct s_node *root);


struct s_node	*new_node(int val)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->value = val;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

int		main()
{
	struct s_node	*tree;

	tree = new_node(95);
	tree->right = new_node(26);
//	tree->right->left = new_node(32);
	tree->right->right = new_node(30);

	perimeter(tree);
}