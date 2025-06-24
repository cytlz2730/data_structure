#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//设计哈希节点
struct  HashNode{
    int value;
    int key;
    struct HashNode* next;
};

//设计哈希表
struct HashTable{
    struct HashNode** data; //哈希表节点数据
    int size; //哈希表容量，哈希桶
};


//创建哈希节点
struct HashNode* create_hash_node(int key, int value)
{
    struct HashNode* node = malloc(sizeof(struct HashNode));
    node->key = key;
    node->value = value;
    node->next =NULL;
    return node;
}

//创建哈希表
struct HashTable *create_hash_table(int size){
    struct HashTable * table = malloc(sizeof(struct HashTable));
    table->data = calloc(sizeof(struct HashNode*) ,  size);
    table->size = size;
    return table;
}

//设计一个哈希函数
int  hash_index(int key)
{
    return key%5;
}

//插入数据
void insert(struct HashTable* table, int key,  int value){
    struct HashNode* node = create_hash_node(key, value);

    //通过哈希函数计算索引
    int index = hash_index(key);

    //在哈希表中通过index获取节点头
    struct HashNode* curr = table->data[index];
    if(curr == NULL){
        //没有数据就把node当作第一个数据
        table->data[index] = node;
    }else{
        //遍历到末尾
        while(curr->next != NULL) curr=curr->next;  
        curr->next = node;
    }
}

//显示哈希表
void  show(struct HashTable *table){
    for(int i=0; i<table->size; i++){
        struct HashNode* head = table->data[i];
        if(head == NULL) continue;

        //遍历链表
        while(head != NULL){
            printf("[%d,%d] ", head->key, head->value);
            head = head->next;
        }printf("\n"); 
    }
}



int main(void)
{
    //创建哈希表
    struct HashTable* table = create_hash_table(5);

    for(int i=0; i<18; i++){
        int data = random()%100;
        insert(table, i, data);
    }

    show(table);
}