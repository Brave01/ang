<<<<<<< HEAD
/*
 * 链表测试
 * */
#include <stdio.h>
#include "01link.h"
int main() {
    int size = 0, val = 0, num = 0;
    link lnk = {0};
    link_init(&lnk);
    link_add_head(&lnk, 50);
    link_add_head(&lnk, 30);
    link_append(&lnk, 70);
    link_append(&lnk, 90);
    link_insert(&lnk, 40);
    link_insert(&lnk, 20);
    link_insert(&lnk, 10);
    link_insert(&lnk, 60);
    link_insert(&lnk, 80);
    link_remove_head(&lnk);
    link_remove_tail(&lnk);
    link_remove(&lnk, 50);
    link_get_head(&lnk, &val);
    printf("最前面的数字是%d\n", val);
    link_get_tail(&lnk, &val);
    printf("最后面的数字是%d\n", val);
    size = link_size(&lnk);
    for (num = 0;num <= size - 1;num++) {
        link_get(&lnk, &val, num);
        printf("%d ", val);
    }
    printf("\n");
    link_begin(&lnk);
    while (1) {
        if (!link_next(&lnk, &val)) {
            break;
        }
        printf("%d ", val);
    }
    printf("\n");
    link_deinit(&lnk);
    return 0;
}





=======
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
>>>>>>> bd62252805872e555d751242425b8cede1eb8e7d
