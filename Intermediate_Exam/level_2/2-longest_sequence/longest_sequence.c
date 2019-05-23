//Does not pass Moulinette

#include <stdio.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	recur(struct s_node *node, int *max_len)
{
	if (node == 0)
		return (0);

	int local_len;
	local_len = max(recur(node->left, max_len), recur(node->right, max_len));
	if ((node->left && node->value + 1 == node->left->value)
		|| (node->right && node->value + 1 == node->right->value))
	{
		local_len++;
		if (*max_len < local_len)
			*max_len = local_len;
	}
	else
		local_len = 1;

	return (local_len);
}

int	longest_sequence(struct s_node *node)
{
	int max_len = 0;
	recur(node, &max_len);
	return (max_len);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}
// int	main(void)
// {
// /*
//            10
//            / \
//           11  9
//          / \   \
//         /   \   \
//        6     9   8
//       / \         \
//      /   \         \
//     7   13          7
//    /                 \
//   /                   \
//  8                     6

// Longest sequence: 3 (6 -> 7 -> 8)
// */
// 	struct s_node *root1 = NODE(
// 		10,
// 		NODE(
// 			11,
// 			NODE(
// 				6,
// 				NODE(7, 
// 					NODE(8, NULL, NULL),
// 					NULL
// 					),
// 				NODE(13, NULL, NULL)
// 				),
// 			NODE(9, NULL, NULL)
// 			),
// 		NODE(
// 			9,
// 			NODE(
// 				8,
// 				NODE(
// 					7,
// 					NODE(6, NULL, NULL),
// 					NULL
// 					),
// 				NULL
// 				),
// 			NULL)
// 		);
// 	printf("%d\n", longest_sequence(root1));

// 	struct s_node *root2 = NULL;
// 	printf("%d\n", longest_sequence(root2));

// 	struct s_node *root3 = NODE(1, NODE(2, NODE(3, NODE(4, NULL, NULL), NULL), NULL), NULL);
// 	printf("%d\n", longest_sequence(root3));
// }