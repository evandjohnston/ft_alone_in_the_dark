	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

#include <stdio.h>
#define LEAF(node)	(!node->left && !node->right)

void	leftmost_nodes(struct s_node *node)
{
	if (node && !LEAF(node))
	{
		printf(" %d", node->value);
		leftmost_nodes(node->left);
	}
}

void	rightmost_nodes(struct s_node *node)
{
	if (node && !LEAF(node))
	{
		rightmost_nodes(node->right);
		printf(" %d", node->value);
	}
}

void	leaf_nodes(struct s_node *node)
{
	if (node)
	{
		if (LEAF(node))
			printf(" %d", node->value);
		else
		{
			leaf_nodes(node->left);
			leaf_nodes(node->right);
		}
	}
}

void perimeter(struct s_node *root)
{
	if (!root)
		return ;

	printf("%d", root->value);
	if (!LEAF(root))
	{
		leftmost_nodes(root->left);
		leaf_nodes(root);
		rightmost_nodes(root->right);
	}
	printf("\n");
}