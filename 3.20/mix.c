#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node_t;

//添加新结点
Node_t * addNewNode(int data){
    Node_t *newNode;
    newNode=malloc(sizeof(Node_t));
    if(newNode==NULL){
        printf("Error:Allocate Fail!");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int ifdigit(int ch){
    if(ch>='0'&&ch<='9'){
        return 1;
    }
    return 0;
}

void insertTail(Node_t **head,int num){
    Node_t *newNode=addNewNode(num);
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

void input(Node_t **head){
    int ch;
    int num=0;
    while((ch=getchar())!=EOF){
        if(ifdigit(ch)){
            num=num*10+ch-'0';
        }else{
            insertTail(head,num);
            num=0;
            if(ch=='\n'){
                break;
            }
        }
    }
}

void printLink(Node_t *head){
    Node_t *temp=head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

int countN(Node_t *head){
    int count=0;
    Node_t *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void order(Node_t *head,int n){
    Node_t *temp=head;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(temp->data>temp->next->data){
                int swap=temp->data;
                temp->data=temp->next->data;
                temp->next->data=swap;
            }
            temp=temp->next;
        }
        temp=head;
    }

}

int main(){
    Node_t * headA=NULL;//创建新链表
    Node_t * headB=NULL;
    Node_t * headC=NULL;
    input(&headA);
    input(&headB);
    order(headA,countN(headA));
    order(headB,countN(headB));
    Node_t *temp1=headA;
    Node_t *temp2=headB;
    while(temp1!=NULL||temp2!=NULL){
        if(temp1==NULL){
            while(temp2!=NULL){
                insertTail(&headC,temp2->data);
                temp2=temp2->next;
            }
            break;
        }
        if(temp2==NULL){
            while(temp1!=NULL){
                insertTail(&headC,temp1->data);
                temp1=temp1->next;
            }
            break;
        }
        if(temp1->data>temp2->data){
            insertTail(&headC,temp2->data);
            temp2=temp2->next;
        }else{
            insertTail(&headC,temp1->data);
            temp1=temp1->next;
        }
    }
    printLink(headC);    
    return 0;
}