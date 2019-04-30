#include <string.h>
#include <stdio.h>

typedef struct		s_node {
	int				value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

void	print_tree_left(t_node *node)
{
	printf("%d, ", node->value);
	if (node->left)
			print_tree_left(node->left);
}

int main()
{
//	Ryan (rwright)'s approach
	t_node *root_a = &(t_node) { .value = 5,
		.left = &(t_node) { .value = 3,
			.left = &(t_node) {.value = 1,
				.left = &(t_node) { .value = 16 },
			},
			.right = &(t_node) {.value = 8 },
		}
	};

	print_tree_left(root_a);
	printf("\n");
//----------------------------

//	Armando (arherrer)'s approach
#define NODE(V, L, R) &(t_node){.value = V, .left = L, .right = R}
	t_node *root_b = NODE(5,
		NODE(3,
			NODE(16, 
				NODE(8, NULL, NULL),
				NODE(4, NULL, NULL)
				),
			NODE(2, NULL, NULL)
			),
		NODE(6,
			NODE(5, NULL, NULL), 
			NODE(5, NULL, NULL)
			)
		);

	print_tree_left(root_b);
	printf("\n");
}
