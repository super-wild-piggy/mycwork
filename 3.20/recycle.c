#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *last;
};
typedef struct node node_t;

node_t * CreateNode(int data){
    node_t *newNode=NULL;
    newNode=malloc(sizeof(node_t));
    if(newNode==NULL){
        printf("分配失败\n");
        return NULL;
    }
    newNode->data=data;
    newNode->last=NULL;
    newNode->next=NULL;
    return newNode;
}

void InsertLink(node_t *head,int data,int pos){
    node_t *temp=head;
    node_t *te_pre=NULL;
    node_t *te_nex=head->next;
    for(int i=0;i<pos;i++){
        te_pre=temp;
        temp=temp->next;
    }
    te_nex=temp;
    te_pre=temp->last;
    node_t *new=CreateNode(data);
    te_pre->next=new;
    new->last=te_pre;
    new->next=te_nex;
    te_nex->last=new;
}

void deleteLink(node_t *head,int pos){
    node_t *temp=head;
    node_t *pre=NULL;
    node_t *nex=NULL;
    for(int i=0;i<pos;i++){
        pre=temp;
        temp=temp->next;
    }
    nex=temp->next;
    free(temp);
    nex->last=pre;
    pre->next=nex;
}

void freeLink(node_t *head){
    node_t *temp=head;
    node_t *tem_pre=NULL;
    while(temp!=NULL){
        tem_pre=temp;
        temp=temp->next;
        free(tem_pre);
    }
}

void printLink(node_t *head){
    node_t *temp=head->next;
    while(temp!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void input(node_t *head){
    int is_type=0;
    int type=-1;
    int in_num=0;
    int num=0;
    int ch;
    int sign=1;
    int ifdata=0;
    int ifpos=0;
    int data=-1;//用于储存模式1的数据
    int pos1=-1;//用于储存模式1的位置
    int pos2=-1;//用于储存模式2的位置
    while((ch=getchar())!=EOF){
        if(!is_type){
            type=ch-'0';
            is_type=1;
        }else{
            if(type==0){
                printLink(head);
                type=-1;
                is_type=0;
            }else if(type==1){
                if(ch>='0'&&ch<='9'){
                    in_num=1;
                    num=num*10+ch-'0';
                }else if(ch=='-'){
                    sign=-1;
                }else{
                    if(!ifpos&&!ifdata&&in_num){
                        pos1=num;
                        in_num=0;
                        sign=1;
                        ifpos=1;
                        num=0;
                    }else if(ifpos&&!ifdata&&in_num){
                        data=num*sign;
                        in_num=0;
                        sign=1;
                        ifdata=1;
                        num=0;
                        InsertLink(head,data,pos1);
                        data=-1;
                        pos1=-1;
                        ifpos=0;
                        ifdata=0;
                    }
                }
            }else if(type==2){
                if(ch>='0'&&ch<='9'){
                    in_num=1;
                    num=num*10+ch-'0';
                }else if(in_num){
                    pos2=num;
                    num=0;
                    deleteLink(head,pos2);
                    in_num=0;
                    pos2=-1;
                }
            }
        }
        if(ch=='\n'){
            is_type=0;
            type=-1;
        }
    }
}

int main(){
    node_t *head=NULL;
    head=malloc(sizeof(node_t));
    head->next=head;//第一个节点为头节点（空的）
    head->last=head;
    int pos;
    int data;
    int type;
    while(scanf("%d",&type)!=EOF){
        if(type==0){
            printLink(head);
        }else if(type==1){
            scanf("%d%d",&pos,&data);
            InsertLink(head,data,pos);
        }else if(type==2){
            scanf("%d",&pos);
            deleteLink(head,pos);
        }else{
            printf("模式错误\n");
            return -1;
        }
    }

    freeLink(head);
    return 0;
}