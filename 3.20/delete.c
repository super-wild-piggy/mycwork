#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node_t;

Node_t * createNode(int data){
    Node_t *newNode=NULL;
    newNode=malloc(sizeof(Node_t));
    if(newNode==NULL){
        printf("分配失败");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertNode(Node_t **head,Node_t *newNode){
    if(*head==NULL){
        *head=newNode;
    }else{
        Node_t *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void inputLink(Node_t **head){
    int ch;
    int num=0;
    while((ch=getchar())!=EOF){
        if(ch>='0'&&ch<='9'){
            num=num*10+ch-'0';
        }else{
            Node_t *newNode=createNode(num);
            insertNode(head,newNode);
            num=0;
        }
        if(ch=='\n'){
            break;
        }
    }
}

void printLink(Node_t *head){
    Node_t *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void freeLink(Node_t *head){
    Node_t *temp=NULL;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

void deleteNode(Node_t **head,int x){
    Node_t *delete=NULL;//用于保存要删除的节点
    Node_t *prev=NULL;//上一个节点
    Node_t *temp=*head;
    while(temp!=NULL){
        if(temp->data<x){
            if(temp==*head){
                delete=temp;
                temp=temp->next;
                *head=temp;
                free(delete);
            }else{
                delete=temp;
                temp=temp->next;
                prev->next=temp;
                free(delete);
            }
        }else{
            prev=temp;
            temp=temp->next;
        }
    }

}

int main(){
    Node_t *head=NULL;
    inputLink(&head);
    if(head==NULL){
        printf("链表创建失败\n");
        return 1;
    }
    printf("请输入x\n");
    int x;
    scanf("%d",&x);
    deleteNode(&head,x);
    printLink(head);
    freeLink(head);
    return 0;
}