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





