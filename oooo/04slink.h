/*
 * 链表演示 --- > 双向链表
 */
#ifndef __04SLINK_H__
#define __04SLINK_H__
typedef struct node{
   int val;
   struct node *p_prev;
   struct node *p_next;
} node;
typedef struct {
   node head;
   node tail;
   node *p_cur;
}link;
//链表初始化函数
void link_init(link *);
//链表清理函数
void link_deinit(link *);
//链表中包含数字的个数函数
int link_size(const link *);
//在链表最前面增加数字的函数
int link_add_head(link *,int );
//在链表最后加入新数字的函数
int link_append(link *,int );
//按照从小到达的顺序在链表里加入新数字的函数
int link_insert(link *,int );
//从链表中删除最前的数字
int link_remove_head(link *);
//删除最后面数字的函数
int link_remove_tail(link *);
//删除某个数字的函数
int link_remove(link *,int );
//获得最前面的数字的函数
int link_get_head(const link *,int *);
//获得最后数字的函数
int link_get_tail(const link *,int *);
// 根据编号找到数字的函数
int link_get(const link *,int *,int );
//开始从前向后遍历
void link_begin(link *);
//开始从前向后遍历获得下一个数字
int link_next(link *, int *);


#endif    //__04SLINK_H__
