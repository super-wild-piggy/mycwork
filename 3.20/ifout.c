#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
typedef struct stack stack_t;

void push(stack_t *s,int data){
    stack_t *new=malloc(sizeof(stack_t));
    new->data=data;
    if(s->next==NULL){
        s->next=new;
        new->next=NULL;
    }else{
        new->next=s->next;
        s->next=new;
    }
}

void pop(stack_t *s){
    stack_t *delete=s->next;
    int data=delete->data;
    s->next=delete->next;
    free(delete);
}

void freeStack(stack_t *s){
    if(s->next==NULL){
        free(s);
    }else{
        stack_t *temp=s;
        stack_t *prev=NULL;
        while(temp!=NULL){
            prev=temp;
            temp=temp->next;
            free(prev);
        }
    }
}

int main(){
    stack_t *s=malloc(sizeof(stack_t));
    s->next=NULL;//初始化栈;
    int num;
    scanf("%d",&num);
    int in[num];
    int out[num];
    for(int i=0;i<num;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<num;i++){
        scanf("%d",&out[i]);
    }
    int j=0;//out
    int k=0;//in
    int count=0;
    while(j<num){
        if(in[k]!=out[j]&&s->next==NULL){
            push(s,in[k]);
            k++;
        }  
        else if(in[k]!=out[j]&&s->next->data==out[j]){
            pop(s);
            count++;
            j++;
        }else if(in[k]==out[j]){
            push(s,in[k]);
            pop(s);
            count++;
            j++;
            k++;
        }else if(in[k]!=out[j]&&s->next->data!=out[j]&&k!=num){
            push(s,in[k]);
            k++;
        }else{
            count=0;
            freeStack(s);
            break;
        }
    }
    printf("%d",count);
    freeStack(s);
    return 0;
}