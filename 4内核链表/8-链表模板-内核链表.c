#include <stdio.h>
#include <stdlib.h>

//设计链表结构体
struct list_head{
    struct list_head *prev, *next;
};
//初始化节点
void  init_list_head(struct list_head *node){
    node->prev = node->next = node;
}
//插入-头插入
void   list_add(struct list_head *head,  struct list_head *newnode)
{
    newnode->prev = head;
    newnode->next = head->next;
    head->next->prev = newnode;
    head->next = newnode;
}
//插入-尾插入
void   list_add_tail(struct list_head *head,  struct list_head *newnode)
{
    list_add(head->prev , newnode);
}
//删除
void  list_del(struct list_head *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;    
}


//设计一个数据结构体（学生结构体）
struct Student {
    char name[32];
    char sex[2];
    int number;
    struct list_head list;
};

int main(void){

    struct Student *shead = malloc(sizeof(struct Student));//数据结构体头（不存数据）
    //初始化连接结构体
    init_list_head(&shead->list);

    //创建学生对象，并且插入到链表中
    for(int i=0; i<3; i++){

        struct Student*  pstu = malloc(sizeof(struct Student));
        printf("请输入姓名，性别,学号：");scanf("%s %s %d", pstu->name, pstu->sex, &pstu->number);
        //初始化连接结构体
        init_list_head(&pstu->list);

        //把新建的学生结构体里面的链表结构体， 插入到shead里面的链链表
        list_add(&shead->list,  &pstu->list);
    }

    //遍历输出学生信息
    //shead不存储信息，所以从->next开始
    struct list_head *p = shead->list.next;

    while(p != (&shead->list))
    {
        //通过p（连接结构体地址)计算数据结构体（学生结构体的首地址）
        //取地址运算符 & 的优先级 低于 指针访问运算符 ->
        //(&((struct Student*)0)->list)---strcut Student和成员list的偏移量
        
        struct Student *pos  =  (struct Student*)((char*)p - (char*)(&((struct Student*)0)->list));
        printf("[%s   %s    %d]\n", pos->name, pos->sex, pos->number);
        p = p->next;
    }

}
