/*
 * 二叉树演示
 */
struct node;
typedef struct {
   struct node *p_node;
} tree;
typedef struct {
   int val;
   tree left;
   tree right;
} node;
