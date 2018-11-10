/*
 * 队列测试
 */
#include <stdio.h>
#include "02queue.h"

int main()
{
   queue que = {0};
   int str[10] = {0};
   queue_init(&que);
   queue_deinit(&que);   
   printf("队列个数:%d\n",queue_size(&que)); 
   if(queue_empty(&que));
   {
       printf("队列是空的\n");
   } 
   if(queue_full(&que))
   {
       printf("队列是满的\n");
   }
   queue_push(&que,10);
   queue_push(&que,20);
   queue_push(&que,30);
   queue_push(&que,40);
   queue_pop(&que,str);
   queue_pop(&que,str+1);
   queue_pop(&que,str+2);
   queue_pop(&que,str+3);
   printf("队列个数:%d\n",queue_size(&que));
   printf("%d ",str[0]);
   printf("%d ",str[1]);
   printf("%d ",str[2]);
   printf("%d\n",str[3]);
   printf("队列个数:%d\n",queue_size(&que));
   if(queue_empty(&que));
   {
       printf("队列是空的\n");
   }
   if(queue_full(&que))
   {
       printf("队列是满的\n");
   }
  
   
 
   return 0;
}
