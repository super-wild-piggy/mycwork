#include <stdio.h>
#include <stdlib.h>

struct stack{
    int direcation;
    int step;
    int x;
    int y;
    struct stack *next;
};
typedef struct stack stack_t;

void push(stack_t *s,int direcation,int step){
    stack_t *new=malloc(sizeof(stack_t));
    new->direcation=direcation;
    new->step=step;
    if(s->next==NULL){
        s->next=new;
        new->next=NULL;
        if(direcation==3){
            new->x=(-1)*step;
            new->y=0;
        }else if(direcation==4){
            new->x=step;
            new->y=0;
        }else if(direcation==1){
            new->y=step;
            new->x=0;
        }else if(direcation==2){
            new->y=(-1)*step;
            new->x=0;
        }
    }else{
        new->next=s->next;
        s->next=new;
        if(direcation==3){
            new->x=(-1)*step+new->next->x;
            new->y=new->next->y;
        }else if(direcation==4){
            new->x=step+new->next->x;
            new->y=new->next->y;
        }else if(direcation==1){
            new->y=step+new->next->y;
            new->x=new->next->x;
        }else if(direcation==2){
            new->y=(-1)*step+new->next->y;
            new->x=new->next->x;
        }
    }
}

void pop(stack_t *s){
    stack_t *delete=s->next;
    s->next=delete->next;
    free(delete);
}

void ifcompose(stack_t *s,int direcation1,int direcation2){//合并函数的判断过程
    if(s->next->next->direcation==direcation1){
        s->next->next->step+=s->next->step;
        pop(s);
    }else if(s->next->next->direcation==direcation2){
        if(s->next->next->step>s->next->step){
            s->next->next->step-=s->next->step;
            pop(s);
        }else if(s->next->next->step<s->next->step){
            s->next->next->step=s->next->step-s->next->next->step;
            s->next->next->direcation=direcation1;
            pop(s);
        }else{
            pop(s);
            pop(s);
        }
    }  
}

void compose(stack_t *s){//入栈后和上一个入栈元素合并
    switch(s->next->direcation){
        case 1:
        ifcompose(s,1,2);
        break;
        case 2:
        ifcompose(s,2,1);
        break;
        case 3:
        ifcompose(s,3,4);
        break;
        case 4:
        ifcompose(s,4,3);
        break;
    }
}

void deleteRoad(stack_t *s){
    int count=0;
    int find=0;
    int x=s->next->x;
    int y=s->next->y;
    stack_t *temp=s->next;
    while(temp!=NULL){
        if(temp->x==x&&temp->y==y){
            find=1;
            break;
        }
        count++;
        temp=temp->next;
    }
    if(find){
        for(int i=0;i<count;i++){
            pop(s);
        }
    }
}

int back(int direction){
    int ret;
    switch (direction){
        case 1:
        ret=2;
        break;
        case 2:
        ret=1;
        break;
        case 3:
        ret=4;
        break;
        case 4:
        ret=3;
        break;
    }
    return ret;
}

void print_destory(stack_t *s){
    while(s->next!=NULL){
        s->next->direcation=back(s->next->direcation);
        printf("%d-%d ",s->next->direcation,s->next->step);
        pop(s);
    }
    free(s);
}

int main(){
    stack_t *s=malloc(sizeof(stack_t));
    s->next=NULL;
    int direction=0;
    int step=0;
    scanf("%d-%d",&direction,&step);
    while(direction!=0&&step!=0){
        if(s->next==NULL){
            push(s,direction,step);
        }else{
            push(s,direction,step);
            compose(s);
            deleteRoad(s);
        }
        scanf("%d-%d",&direction,&step);        
    }
    print_destory(s);
    return 0;
}