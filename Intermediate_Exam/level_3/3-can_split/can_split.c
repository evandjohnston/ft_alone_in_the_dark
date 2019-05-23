// This code passed Moulinette 2019.05.19, even though it should fail.

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	count_nodes(struct s_node *n)
{
	if (!n)
		return (0);
	return (1 + count_nodes(n->left) + count_nodes(n->right));
}

int	can_split(struct s_node *n)
{
	return (count_nodes(n) % 2 == 0);
}

//--------------------------------------------------------------
// #include <stdio.h>
// #define NODE(value, left, right) &(struct s_node){value, left, right}

// int	print_in_order(struct s_node *node)
// {
// 	if (!node)
// 		return (0);

// 	if (node->left)
// 		print_in_order(node->left);
// 	printf("%d, ", node->value);
// 	if (node->right)
// 		print_in_order(node->right);
// 	return (1);
// }

// int	main(void)
// {
// 	//            10
// 	//            / \
// 	//           11  9
// 	//          / \   \
// 	//         /   \   \
// 	//        6     9   8
// 	//       / \         \
// 	//      /   \         \
// 	//     7   13          7
// 	//    /                 \
// 	//   /                   \
// 	//  8                     6
// 	// Longest sequence: 3 (6 -> 7 -> 8)

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
// 					NULL,//NODE(6, NULL, NULL),
// 					NULL
// 					),
// 				NULL
// 				),
// 			NULL)
// 		);
// 	printf("%d\n", can_split(root1));
// }