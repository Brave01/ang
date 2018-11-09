#include <stdio.h>

typedef struct{
   int buf[SIZE];
   int qty;
}stack;
// 栈的初始化
void stack_init(stack *p_stack)
{
   p_stack->qty = 0;
}
// 清理栈内容的函数
void stack_deinit(stack *p_stack)
{
   p_stack->qty = 0;
}
// 判断栈是否满的函数
int stack_full(const stack *p_stack)
{
   return p_stack->qty >= SIZE;
} 
// 判断栈是不是空的
int stack_empty(const stack *p_stack)
{
   return !(p_stack->qty);
}
// 获得数字个数的函数
int stack_size(const stack *p_stack)
{
    return p_stack->qty;
}
// 向栈里加入数字的函数
int stack_push(stack *p_stack,int val)
{
    if(p_stack->qty >= SIZE)
    {
        return 0;
    }
    p_stack->buf[p_stack->qty] = val;
    p_stack->qty++;
    return 1;
}
// 从栈里获得数字的函数(同时从栈里把数字删除掉)
int stack_pop(stack *p_stack,int *p_val)
{
    if(!(p_stack->qty))
    {
       return 0;
    }
    *p_val = p_stack->buf[p_stack->qty-1];
     p_stack->qty--;
    return 1;
}
// 获得最后一个数字的函数(不会删除数字)
int stack_stop(const stack *p_stack,int *p_val)
{
    if(!(p_stack->qty))
    {
      return 0;
    }
    *p_val = p_stack->buf[p_stack->qty-1];
    return 1;
}
