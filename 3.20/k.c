#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node_t;

node_t *createNode(int data){
    node_t *new=NULL;
    new=malloc(sizeof(node_t));
    new->data=data;
    new->next=NULL;
}

void insertNode(int data,node_t *head){//默认头结点有数据
    node_t *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node_t *new=createNode(data);
    temp->next=new;
}

node_t* createLink(int *count){
    int ch;
    int num=0;
    int in_num=0;
    int sign=1;
    int have_head=0;
    node_t *head;
    while((ch=getchar())!=EOF){
        if(ch>='0'&&ch<='9'){
            in_num=1;
            num=num*10+ch-'0';
        }else if(ch=='-'){
            sign=-1;
        }else{
            if(in_num&&!have_head){
                head=createNode(sign*num);
                have_head=1;
                (*count)++;
            }else if(in_num&&have_head){
                insertNode(num*sign,head);
                (*count)++;
            }
            in_num=0;
            sign=1;
            num=0;
        }
    }
    return head;
}

void freeLink(node_t *head){
    node_t *prev=NULL;
    node_t *temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        free(prev);
    }
    free(temp);
}

int main(){
    int *count;
    count=malloc(sizeof(int));
    *count=0;
    int k;
    scanf("%d",&k);
    node_t *head=createLink(count);
    node_t *temp=head;
    for(int i=0;i<*count-k;i++){
        temp=temp->next;
    }
    printf("%d",temp->data);
    free(count);
    return 0;
}

