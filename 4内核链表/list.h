#ifndef _LINUX_LIST_  
#define _LINUX_LIST_

#include <stdbool.h>  
#include <stdio.h>    

// 定义链表结构体
struct list_head {
    struct list_head *next, *prev;  // 指向前后节点的指针
};

// 计算结构体成员的偏移量
// type为结构体类型
// member为结构体内的链表成员
#define offsetof(type, member)  (char*)(&((type*)0)->member)

// 通过链表指针获取数据结构体指针
// ptr指的是要求的结构体的链表成员
#define container_of(ptr, type, member)  ({  ((type *)((char*)ptr - offsetof(type, member))); })

// 通过链表指针获取其所在的结构体指针
#define list_entry(ptr, type, member)   container_of(ptr, type, member)

// 初始化一个链表头
#define LIST_HEAD_INIT(name)  { &(name), &(name) }

// 定义链表头变量
#define LIST_HEAD(name)   struct list_head name = LIST_HEAD_INIT(name)

// 初始化链表头，使其指向自身
static inline void INIT_LIST_HEAD(struct list_head *list)
{
    if(list == NULL) return;
    list->next = list;
    list->prev = list;
}

// 插入一个新节点到指定位置
static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

// 在链表头部插入新节点
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

// 在链表尾部插入新节点
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

// 删除节点
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}

// 删除链表中的一个节点
static inline void __list_del_entry(struct list_head *entry)
{
    if(entry == NULL) return;
    __list_del(entry->prev, entry->next);
}

// 删除节点并使其指针指向自身
static inline void list_del(struct list_head *entry)
{
    __list_del_entry(entry);
    entry->next = entry;
    entry->prev = entry;
}

// 获取链表中的第一个节点
#define list_first_entry(ptr, type, member)   list_entry((ptr)->next, type, member)

// 判断当前节点是否为链表头
#define list_entry_is_head(pos, head, member)   (&pos->member == (head))

// 获取下一个节点
#define list_next_entry(pos, member)  list_entry((pos)->member.next, typeof(*(pos)), member)

// 遍历链表（不可删除节点）
#define list_for_each_entry(pos, head, member)                          \
    for (pos = list_first_entry(head, typeof(*pos), member);        \
         !list_entry_is_head(pos, head, member);                    \
         pos = list_next_entry(pos, member))

// 安全遍历链表（可删除节点）
#define list_for_each_entry_safe(pos, n, head, member)                  \
    for (pos = list_first_entry(head, typeof(*pos), member),        \
         n = list_next_entry(pos, member);                       \
         !list_entry_is_head(pos, head, member);                    \
         pos = n, n = list_next_entry(n, member))

#endif // _LINUX_LIST_

