#include <stdio.h>
#include "01stack.h"

int main()
{
   int val = 0;
   stack stk = {0};
   stack_init(&stk);
   printf("判断空的结果是%d\n",stack_empty(&stk));
   printf("判断满的结果是%d\n",stack_full(&stk));
   printf("判断栈的个数结果是%d\n",stack_size(&stk));
   stack_push(&stk,10);
   stack_push(&stk,20);
   stack_push(&stk,30);
   printf("判断空的结果是%d\n",stack_empty(&stk));
   printf("判断满的结果是%d\n",stack_full(&stk));
   printf("判断栈的个数结果是%d\n",stack_size(&stk));
   stack_stop(&stk,&val);
   printf("最后一个数字%d\n",val);
   stack_pop(&stk,&val);
   printf("%d ",val);
   stack_pop(&stk,&val);
   printf("%d ",val);
   stack_pop(&stk,&val);
   printf("%d\n",val);
   printf("判断空的结果是%d\n",stack_empty(&stk));
   printf("判断满的结果是%d\n",stack_full(&stk));
   printf("判断栈的个数结果是%d\n",stack_size(&stk));
   
	
   stack_deinit(&stk);

   return 0;
}
