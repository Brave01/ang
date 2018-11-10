/*
 * 链表演示 --- > 双向链表
 */
#include <stdlib.h>
#include "04slink.h"

//链表初始化函数
void link_init(link *p_link)
{
   p_link->head.p_next = &(p_link->tail);
   p_link->tail.p_next = NULL;
   p_link->tail.p_prev = &(p_link->head);
   p_link->head.p_prev = NULL;
   p_link->p_cur = NULL;
}
//链表清理函数
void link_deinit(link *p_link)
{
   p_link->p_cur = NULL;
   while(p_link->head.p_next != &(p_link->tail))
   {
      node *p_first = &(p_link->head);
      node *p_mid = p_first->p_next;
      node *p_last = p_mid->p_next;
      p_first->p_next = p_last;
      p_last->p_prev = p_first;
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
   node *p_node = NULL;
   p_link->p_cur = NULL; //
   p_node = (node *)malloc(sizeof(node));
   if(!p_node)
   {
      return 0;
   }
   p_node->val = val;
   p_node->p_prev = NULL;
   p_node->p_next = NULL;
   p_first = &(p_link->head);
   p_mid = p_first->p_next;
   p_last = p_mid->p_next;
   p_first->p_next = p_node;
   p_node->p_next = p_mid;
   p_mid->p_prev = p_node;
   p_node->p_prev = p_first;
   return 1;
}


//在链表最后加入新数字的函数
int link_append(link *p_link,int val)
{
   node *p_first = NULL,*p_mid = NULL,*p_last = NULL;
   node *p_node = NULL;
   p_link->p_cur = NULL;
   p_node = (node *)malloc(sizeof(node));
   if(!p_node)
   {
     return 0;
   }
   p_node->val = val;
   p_node->p_prev = NULL;
   p_node->p_next = NULL;
   p_mid = &(p_link->tail);
   p_first = p_mid->p_prev;
   p_last = p_mid->p_next;
   p_first->p_next = p_node;
   p_node->p_next = p_mid;
   p_mid->p_prev = p_node;
   p_node->p_prev = p_first;

   return 1;
}
/*
int link_append(link *p_link,int val)
{
   node *p_tmp = NULL;
   node *p_node = NULL;
   p_link->cur = NULL;
   p_node = (node *)malloc(sizeof(node));
   if(!p_node)
   {
      return 0;
   }
   p_node->val = val;
   p_node->p_prev = NULL;
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
              p_mid->p_prev = p_node;
              p_node->p_prev = p_first; 
             break;
         }
   }
   return 1;
}
*/
#if 0
//按照从小到达的顺序在链表里加入新数字的函数
int link_insert(link *p_link,int val)
{
     node *p_tmp = NULL;
     node *p_node = NULL;
     p_link->p_cur = NULL;
     p_node = malloc(sizeof(node));
     if(!p_node)
     {
        return 0;
     }
     p_node->val = val;
     p_node->p_prev = NULL;
     p_node->p_next = NULL;
     for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
     {
         node *p_first = p_tmp;
         node *p_mid = p_first->p_next;
         node *p_last = p_mid->p_next;
         if (p_mid == &(p_link->tail) || p_mid->val > val)
          {
              p_first->p_next = p_node;
              p_node->p_next = p_mid;
              p_mid->p_prev = p_node;
              p_node->p_prev = p_first;
              break;
          }
     }
    return 1;
}
#endif
int link_insert(link *p_link, int val) {
    node *p_tmp = NULL;
    node *p_node = NULL;
    p_link->p_cur = NULL;
    p_node = (node *)malloc(sizeof(node));
    if (!p_node) {
        return 0;
    }
    p_node->val = val;
    p_node->p_prev = NULL;
    p_node->p_next = NULL;
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        node *p_first = p_tmp;
        node *p_mid = p_first->p_next;
        node *p_last = p_mid->p_next;
        if (p_mid == &(p_link->tail) || p_mid->val > val) {
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            p_mid->p_prev = p_node;
            p_node->p_prev = p_first;
            break;
        }
    }
    return 1;
}
//从链表中删除最前的数字
int link_remove_head(link *p_link)
{
   node *p_first = NULL,*p_mid = NULL,*p_last = NULL;
   p_link->p_cur = NULL;
   p_first = &(p_link->head);
   p_mid = p_first->p_next;
   p_last = p_mid->p_next;
   if(p_mid != &(p_link->tail))
   {
     p_first->p_next = p_last;
     p_last->p_prev = p_first;
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
   node *p_first = NULL,*p_mid = NULL,*p_last = NULL;
   p_link->p_cur = NULL;
   p_last = &(p_link->tail);
   p_mid = p_last->p_prev;
   p_first = p_mid->p_prev;
   
   if(p_mid != &(p_link->head))
   {
      p_first->p_next = p_last;
      p_last->p_prev = p_first;
      free(p_mid);
      p_mid = NULL;
      return 1;
   }
   else
   {
      return 0;
   }
}
/*
int link_remove_tail(link *p_link)
{
   node *p_tmp = NULL;
   p_link->p_cur = NULL;
   for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
   {
       node *p_first = &(p_link->head);
       node *p_mid = p_first->p_next;
       node *p_last = p_mid->p_next;
       if(p_last == &(p_link->tail))
       {
          p_first->p_next = p_last;
          p_last->p_prev = p_first;
          free(p_mid);
          p_mid = NULL;
          return 1;
       }
   }
   return 0;
}
*/
//删除某个数字的函数
int link_remove(link *p_link,int val)
{
   node *p_tmp = NULL;
   p_link->p_cur = NULL;
   for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
   {
       node *p_first = &(p_link->head);
       node *p_mid = p_first->p_next;
       node *p_last = p_mid->p_next;
       if(p_mid != &(p_link->tail) && p_mid->val == val)
       {
           p_first->p_next = p_last;
           p_last->p_prev = p_first;
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
   const node *p_first = NULL,*p_mid = NULL,*p_last = NULL;
   p_last = &(p_link->tail);
   p_mid = p_last->p_prev;
   p_first = p_mid->p_prev;
   if(p_mid != &(p_link->head))
   {
      *p_val = p_mid->val;
      return 1;
   }
   else 
   {
      return 0;
   }
}
/*
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
*/
// 根据编号找到数字的函数
int link_get(const link *p_link,int *p_val,int sn)
{    
     int cnt = 0;
     const node *p_tmp = NULL;
     for(p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next)
     {
         const node *p_first = p_tmp;
         const node *p_mid = p_first->p_next;
         const node *p_last = p_mid->p_next;
         if(p_mid != &(p_link->tail) && cnt == sn )
         {
             *p_val = p_mid->val;
             return 1;
         }
         cnt++;
     }
     return 0;
}
//开始从前向后遍历链表
void link_begin(link *p_link)
{
   p_link->p_cur = &(p_link->head);
}
//在从前向后遍历过程中获得下一个数字的函数
int link_next(link *p_link, int *p_val)
{
    if(!(p_link->p_cur))
    {
       return 0;
    }
    p_link->p_cur = p_link->p_cur->p_next;
    if(p_link->p_cur == &(p_link->tail))
    {
        p_link->p_cur = NULL;
        return 0;
    }
    else
    {
        *p_val = p_link->p_cur->val;
        return 1;
    }	
}
