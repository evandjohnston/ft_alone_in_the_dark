// Passed Moulinette 2019.09.01

// #define TEST

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	max(int a, int b)
{
	return(a > b ? a : b);
}

int	recur(struct s_node *n, int *max_width)
{
	if (n == 0)
		return (0);
	int left = recur(n->left, max_width);
	int right = recur(n->right, max_width);
	int local_width = 1 + left + right;

	if (local_width > *max_width)
		*max_width = local_width;

	return (1 + max(left, right));
}

int	width_tree(struct s_node *n)
{
	int max_width = 0;
	recur(n, &max_width);
	return (max_width);
}

#ifdef TEST

#include <stdio.h>
#define NODE(v, l, r) &(struct s_node){v, l, r}

// struct s_node *root = NODE(1, 0, 0);

// &(struct s_node){1,
// 	&(struct s_node){2, 0, 0},
// 	&(struct s_node){3,
// 		0,
// 		0
// 	},
// }

// struct s_node Node(int value, struct s_node left, struct s_node right)
// {
// 	node = malloc(sizeof(struct s_node));
// 	node->value = value;
// 	node->left = left;
// 	node->right = right;
// 	return (node);
// }

void	print_tree(struct s_node *node)
{
	if (!node)
		return;
	print_tree(node->left);
	printf("%d, ", node->value);
	print_tree(node->right);
}

int	main(void)
{
	// struct s_node *root = NODE(
	// 	1,
	// 	NODE(
	// 		2,
	// 		NODE(
	// 			4,
	// 			NODE(
	// 				5,
	// 				NODE(8, 0, 0),
	// 				0
	// 				),
	// 			NODE(6, 0, 0)
	// 			),
	// 		NODE(7,
	// 			NODE(
	// 				9,
	// 				NODE(11, 0, 0),
	// 				NODE(12, 0, 0)
	// 				),
	// 			NODE(
	// 				10,
	// 				0,
	// 				NODE(13, 0, 0)
	// 				)
	// 			)
	// 		),
	// 	NODE(3, 0, 0)
	// 	);

	struct s_node *root = 0; //NODE(1, NODE(2, 0, 0), 0);

	print_tree(root);
	printf("\n");
	printf("width of tree: %d\n", width_tree(root));
}

#endif