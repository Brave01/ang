/*
 * 二叉树演示
 */
#ifndef __01TREE_H__
#define __01TREE_H__
struct node;
typedef struct {
   struct node *p_node;
} tree;
typedef struct node {
   int val;
   tree left;
   tree right;
} node;
// 树的初始化
void tree_init(tree *);
// 树的清理函数
void tree_deinit(tree *);
// 在有序二叉树里查找某个数字的位置
tree *tree_search(const tree *,int );
// 在有序二叉树里插入数字的函数
int tree_insert(tree *,int );
// 以中序遍历的方式依次处理有序二叉树里所有的节点
void tree_miter(const tree *, void (*)(int));
#endif   //__01TREE_H__
