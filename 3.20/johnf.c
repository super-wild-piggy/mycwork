#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;

node_t *createNode(int data){
    node_t *newNode=NULL;
    newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertNode(int data,node_t *head){
    node_t *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node_t *new=createNode(data);
    temp->next=new;
    new->prev=temp;
    new->next=head;
    head->prev=new;
}

node_t *createLink(int size){//只能用于初始的链表创建
    int count=1;
    node_t *head=createNode(count);
    head->prev=head;
    head->next=head;
    count++;
    for(int i=0;i<size-1;i++){
        insertNode(count,head);
        count++;
    }
    return head;
}

void freeLink(node_t *head){
    node_t *temp=head;
    node_t *pre=NULL;
    while(temp->next!=temp){
        pre=temp;
        temp=temp->next;
        free(pre);
    }
    free(temp);
}

int deleteNode(node_t **head,int password){
    node_t *temp=*head;
    for(int i=0;i<password-1;i++){
        temp=temp->next;
    }
    node_t *pre=temp->prev;
    node_t *nex=temp->next;
    int count=temp->data;
    if(temp->next!=temp){
        free(temp);
        pre->next=nex;
        nex->prev=pre;
        *head=nex;
    }else{
        free(temp);
        *head=NULL;
    }
    return count;
}

void change(node_t **head_pre,node_t **head_curr,int password,int size){
    node_t *temp=*head_curr;
    for(int i=0;i<size;i++){
        temp->data=deleteNode(head_pre,password);
        temp=temp->next;
    }
    *head_pre=createLink(size);
}

int main(){
    int size;
    scanf("%d",&size);
    node_t *head1=createLink(size);
    node_t *head2=createLink(size);
    int ret=1;//当前head在1上
    int password;
    while(scanf("%d",&password)!=EOF){
        if(ret==1){
            change(&head1,&head2,password,size);
            ret=2;
        }else if(ret==2){
            change(&head2,&head1,password,size);
            ret=1;
        }
    }
    node_t *temp=NULL;
    if(ret==1){
        temp=head1;
    }else if(ret==2){
        temp=head2;
    }
    for(int i=0;i<size;i++){
        printf("%4d",temp->data);
        temp=temp->next;
    }
    freeLink(head1);
    freeLink(head2);
}

