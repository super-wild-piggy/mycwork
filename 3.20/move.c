#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node_t;

node_t *creatNode(int data){
    node_t *newNode=NULL;
    newNode=malloc(sizeof(node_t));
    if(newNode==NULL){
        printf("分配失败\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertNode(node_t **head,int data){
    node_t *temp=*head;
    if(temp==NULL){
        *head=creatNode(data);
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=creatNode(data);
    }
    
}

void inputLink(node_t **head){
    int ch;
    int num=0;
    int in_number=0;
    int sign=1;
    while((ch=getchar())!=EOF){
        if(ch>='0'&&ch<='9'){
            num=num*10+ch-'0';
            in_number=1;
        }else if(ch=='-'){
            sign=-1;
        }else{
            if(in_number){
                insertNode(head,num*sign);
                num=0;
                sign=1;
                in_number=0;
            }
        }
        if(ch=='\n'){
            break;
        }
    }
}

int findMax(node_t *head){
    int maxCount=0;
    int max=head->data;
    int currCount=0;
    node_t *temp=head->next;
    while(temp!=NULL){
        currCount++;
        if(temp->data>=max){
            maxCount=currCount;
            max=temp->data;
        }
        temp=temp->next;
    }
    return maxCount;
}

void move(node_t **head,int num){
    int count=findMax(*head);
    node_t *prev=NULL;
    node_t *mov=NULL;
    node_t *temp=*head;
    if(count==0){
        temp=temp->next;
        mov=*head;
        *head=temp;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=mov;
        mov->next=NULL;
    }else if(count==num-1){
        return;
    }else{
        for(int i=0;i<count;i++){
            prev=temp;
            temp=temp->next;
        }
        mov=temp;
        prev->next=temp->next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=mov;
        mov->next=NULL;
    }
}

void freeLink(node_t *head){
    node_t *temp=head;
    node_t *prev=NULL;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        free(prev);
    }
    free(temp);
}

void printLink(node_t *head){
    node_t *temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    int num=0;
    node_t *head=NULL;
    scanf("%d",&num);
    while(getchar()!='\n'){

    }
    printf("请输入链表\n");
    inputLink(&head);
    move(&head,num);
    printLink(head);
    freeLink(head);
    return 0;
}