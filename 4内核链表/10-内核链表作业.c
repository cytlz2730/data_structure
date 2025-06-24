#include "list.h"
#include <stdio.h>
#include <stdlib.h>


//设计一个数据结构体（书本结构体）
struct Book {
    char name[32];
    char author[20];
    float price;
    struct list_head list;
};


int main(void)
{
    struct Book *bhead = malloc(sizeof(struct Book));
    INIT_LIST_HEAD(&bhead->list);

    for(int i=0; i<3; i++){

        //申请数据结构体空间
        struct Book *pbook = malloc(sizeof(struct Book));
        printf("请输入书名，作者名,价格：");scanf("%s %s %f", pbook->name, pbook->author, &pbook->price);

        //初始化链表结构体
        INIT_LIST_HEAD(&pbook->list);
        //把新建的数据结构体添加到头中
        list_add_tail(&pbook->list, &bhead->list);
    }

    //遍历输出
    struct Book *pos = NULL;
    list_for_each_entry(pos, &bhead->list, list){
        printf("%s--%s---%f\n", pos->name, pos->author, pos->price);
    }

}
