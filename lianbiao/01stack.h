#ifndef  _01STACK_H_
#define  _01STACK_H_	
typedef struct{
   int buf[SIZE];
   int qty;
}stack;
// 栈的初始化
void stack_init(stack *);
// 清理栈内容的函数
void stack_deinit(stack *);
// 判断栈是否满的函数
int stack_full(const stack *);
// 判断栈是不是空的
int stack_empty(const stack *);
// 获得数字个数的函数
int stack_size(const stack *);
// 向栈里加入数字的函数
int stack_push(stack *,int );
// 从栈里获得数字的函数(同时从栈里把数字删除掉)
int stack_pop(stack *,int *);
// 获得最后一个数字的函数(不会删除数字)
int stack_stop(const stack *,int *);
#endif   //_01STACK_H_ 
