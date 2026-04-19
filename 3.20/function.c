#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    char *name;
    struct stack *next;
};
typedef struct stack stack_t;

struct node{
    char *name;
    struct node *next;
};
typedef struct node node_t;

void push(stack_t *s,char *name){
    int len=strlen(name);
    stack_t *new=malloc(sizeof(stack_t));
    new->name=malloc(sizeof(char)*(len+1));
    strcpy(new->name,name);
    if(s->next==NULL){
        new->next=NULL;
        s->next=new;
    }else{
        new->next=s->next;
        s->next=new;
    }
}

void pop(stack_t *s){
    stack_t *delete=s->next;
    s->next=delete->next;
    free(delete->name);
    free(delete);
}

void insert(node_t *l,char *name){//尾插法
    node_t *new=malloc(sizeof(node_t));
    int len=strlen(name);
    new->name=malloc(sizeof(char)*(len+1));
    strcpy(new->name,name);
    new->next=NULL;
    if(l->next==NULL){
       l->next=new;
    }else{
        node_t *temp=l;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}

void freeNode(node_t *l){
    node_t *temp=l;
    node_t *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        free(prev->name);
        free(prev);
    }
    free(temp->name);
    free(temp);
}

int main(){
    stack_t *s=malloc(sizeof(stack_t));
    s->next=NULL;
    node_t **l=NULL;//创建一个新的链表数组用于储存调用关系
    node_t *temp=NULL;//用于遍历链表
    int size=0;//链表数组元素的个数
    int tag=-1;
    char name[21];//记录函数名称
    int find=0;//是否找到自己的调用关系
    scanf("%d",&tag);
    getchar();
    scanf("%s",name);
    getchar();
    if(tag!=5){
        printf("ERROR\n");
        return -1;
    }else{
        size++;
        l=malloc(size*sizeof(node_t *));
        l[size-1]=malloc(sizeof(node_t));
        l[size-1]->next=NULL;
        insert(l[size-1],name);
        push(s,name);
    }
    while(s->next!=NULL){
        scanf("%d",&tag);
        getchar();
        if(tag==0){
            pop(s);
        }else if(tag==5){
            scanf("%s",name);
            getchar();
            //添加进入当前栈顶的调用关系
            for(int i=0;i<size;i++){//寻找当前栈顶在链表数组的哪里
                if(strcmp(l[i]->next->name,s->next->name)==0){
                    temp=l[i]->next;
                    while(temp!=NULL){
                        if(strcmp(temp->name,name)==0){
                            find=1;
                        }
                        temp=temp->next;
                    }
                    if(!find){
                        insert(l[i],name);
                    }
                    find=0;
                }
            }
            //入栈
            push(s,name);
            //添加自己的调用关系；
            for(int i=0;i<size;i++){
                if(strcmp(l[i]->next->name,name)==0){
                    find=1;
                    break;
                }
            }
            if(!find){
                size++;
                l=realloc(l,size*sizeof(node_t *));
                l[size-1]=malloc(sizeof(node_t));
                l[size-1]->next=NULL;
                insert(l[size-1],name);
            }
            find=0;
        }else{
            printf("ERROR\n");
            return -1;
        }
    }
    for(int i=0;i<size;i++){
        if(l[i]->next->next!=NULL){
            temp=l[i]->next;
            printf("%s",temp->name);
            printf(":");
            while(temp->next->next!=NULL){
                temp=temp->next;
                printf("%s;",temp->name);
            }
            temp=temp->next;
            printf("%s",temp->name);
            printf("\n");
        }
    }
    for(int i=0;i<size;i++){
        freeNode(l[i]);
    }
    free(l);
    return 0;
}