struct s_node {
    int           value;
    struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
    int i = 0;
    int max = 0;
    int tmp = 0;

    if (!root)
        return -1;
    if (!root->nodes)
        return 0;
    while (root->nodes[i])
    {
        tmp = height_tree(root->nodes[i]);
        max = (tmp > max) ? tmp : max;
        i++;
    }
    return max + 1;
}