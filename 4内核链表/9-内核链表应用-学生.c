#include "list.h"
#include <stdio.h>
#include <stdlib.h>


//设计一个数据结构体（学生结构体）
struct Student {
    char name[32];
    char sex[2];
    int number;
    struct list_head list;
};


int main(void)
{
    struct Student *shead = malloc(sizeof(struct Student));
    INIT_LIST_HEAD(&shead->list);

    for(int i=0; i<3; i++){

        //申请数据结构体空间
        struct Student *pstu = malloc(sizeof(struct Student));
        printf("请输入姓名，性别,学号：");scanf("%s %s %d", pstu->name, pstu->sex, &pstu->number);

        //初始化链表结构体
        INIT_LIST_HEAD(&pstu->list);
        //把新建的数据结构体添加到头中
        list_add_tail(&pstu->list, &shead->list);
    }

    //遍历输出
    struct Student *pos = NULL;
    list_for_each_entry(pos, &shead->list, list){
        printf("%s--%s---%d\n", pos->name, pos->sex, pos->number);
    }

}