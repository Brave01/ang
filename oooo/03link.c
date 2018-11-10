/*
 * 链表演示
 */
#include <stdlib.h>

typedef struct node{
   int val;
   struct node *p_next;
} node;
typedef struct {
   node head;
   node tail;
}link;
//链表初始化函数
void link_init(link *p_link)
{
   p_link->head.p_next = &(p_link->tail);
   p_link->tail.p_next = NULL;
}
//链表清理函数
void link_deinit(link *p_link)
{
   while(p_link->head.p_next != &(p_link->tail))
   {
      node *p_first = &(p_link->head);
      node *p_mid = p_first->p_next;
      node *p_last = p_mid->p_next;
      p_first->p_next = p_last;
      free(p_mid);
      p_mid = NULL;
   } 
}
//链表中包含数字的个数函数
int link_size(const link *p_link)
{
   int cnt = 0;
   const node *p_node = NULL;
   for (p_node = &(p_link->head);p_node != &(p_link->tail);p_node = p_node->p_next)
   {
         const node *p_first = p_node;
         const node *p_mid = p_first->p_next;
         const node *p_last = p_mid->p_next;
         if(p_mid != &(p_link->tail))
         {
             cnt++;
         }
   }
   return cnt;	
}
//在链表最前面增加数字的函数
int link_add_head(link *p_link,int val)
{
   node *p_first = NULL;
   node *p_mid = NULL;
   node *p_last = NULL;
   node *p_node = (node *)malloc(sizeof(node));
   if(!p_node)
   {
      return 0;
   }
   p_node->val = val;
   p_node->p_next = NULL;
   p_first = &(p_link->head);
   p_mid = p_first->p_next;
   p_last = p_mid->p_next;
   p_first->p_next = p_node;
   p_node->p_next = p_mid;
   return 1;
}
//在链表最后加入新数字的函数
int link_append(link *p_link,int val)
{
   node *p_tmp = NULL;
   node *p_node = (node *)malloc(sizeof(node));
   if(!p_node)
   {
      return 0;
   }
   p_node->val = val;
   p_node->p_next = NULL;
   for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
   {
         node *p_first = &(p_link->head);
         node *p_mid = p_first->p_next;
         node *p_last = p_mid->p_next;
         if(p_mid == &(p_link->tail))
         {
              p_first->p_next = p_node;
              p_node->p_next = p_mid; 
             break;
         }
   }
   return 1;
}
//按照从小到达的顺序在链表里加入新数字的函数
int link_insert(link *p_link,int val)
{
     node *p_tmp = NULL;
     node *p_node = malloc(sizeof(node));
     if(!p_node)
     {
        return 0;
     }
     p_node->val = val;
     p_node->p_next = NULL;
     for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
     {
         node *p_first = &(p_link->head);
         node *p_mid = p_first->p_next;
         node *p_last = p_mid->p_next;
         if (p_mid == &(p_link->tail) || p_mid->val > val)
          {
              p_first->p_next = p_node;
              p_node->p_next = p_mid;
              break;
          }
     }
    return 1;
}
//从链表中删除最前的数字
int link_remove_head(link *p_link)
{
   node *p_first = NULL,*p_mid = NULL,*p_last = NULL;
   p_first = &(p_link->head);
   p_mid = p_first->p_next;
   p_last = p_mid->p_next;
   if(p_mid != &(p_link->tail))
   {
     p_first->p_next = p_last;
     free(p_mid);
     p_mid = NULL;
     return 1;
   }
   else
   {
     return 0;
   }
}
//删除最后面数字的函数
int link_remove_tail(link *p_link)
{
   node *p_tmp = NULL;
   for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
   {
       node *p_first = &(p_link->head);
       node *p_mid = p_first->p_next;
       node *p_last = p_mid->p_next;
       if(p_last == &(p_link->tail))
       {
          p_first->p_next = p_last;
          free(p_mid);
          p_mid = NULL;
          return 1;
       }
   }
   return 0;
}
//删除某个数字的函数
int link_remove(link *p_link,int val)
{
   node *p_tmp = NULL;
   for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
   {
       node *p_first = &(p_link->head);
       node *p_mid = p_first->p_next;
       node *p_last = p_mid->p_next;
       if(p_mid != &(p_link->tail) && p_mid->val == val)
       {
           p_first->p_next = p_last;
           free(p_mid);
           p_mid = NULL;
           return 1;
       }
   }
   return 0;
}
//获得最前面的数字的函数
int link_get_head(const link *p_link,int *p_val)
{
   const node *p_first = NULL,*p_mid = NULL,*p_last = NULL;
   p_first = &(p_link->head);
   p_mid = p_first->p_next;
   p_last = p_mid->p_next;
   if(p_mid != &(p_link->tail))
   {
     *p_val = p_mid->val;
     return 1;
   }
   else
   {
     return 0;
   }
}
//获得最后数字的函数
int link_get_tail(const link *p_link,int *p_val)
{
   const node *p_tmp = NULL;
   for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
   {
       const node *p_first = &(p_link->head);
       const node *p_mid = p_first->p_next;
       const node *p_last = p_mid->p_next;
       if(p_last == &(p_link->tail))
       {
           *p_val = p_mid->val;
           return 1;
       }
   }
   return 0;
}
// 根据编号找到数字的函数
int link_get(const link *p_link,int *p_val,int sn)
{    
     int cnt = 0;
     const node *p_tmp = NULL;
     for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
     {
         const node *p_first = &(p_link->head);
         const node *p_mid = p_first->p_next;
         const node *p_last = p_mid->p_next;
         if(p_mid != &(p_link->tail) && cnt == sn)
         {
             *p_val = p_mid->val;
             return 1;
         }
         cnt++;	
     }
     return 0;
}
