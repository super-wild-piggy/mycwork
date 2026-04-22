#include <stdio.h>
#include <stdlib.h>

struct stack{
    int number;
    int level;//运算等级 数字为0 相当于没有 + -为1 */% 2 ( 3   )0
    struct stack *next;
};
typedef struct stack stack_t;

void push(stack_t *s,int number,int level){
    stack_t *new=malloc(sizeof(stack_t));
    new->number=number;
    new->level=level;
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
    s->next=delete->next;
    free(delete);
}

int calculateLevel(int ch){
    int level;
    switch(ch){
        case '+':
        case '-':
        level=1;
        break;
        case '*':
        case '/':
        case '%':
        level=2;
        break;
        case '(':
        level=3;
        break;
        case ')':
        level=0;
        break;
    }
    return level;
}

int calculate(int sign,int num1,int num2){
    int ret;
    switch(sign){
        case '+':
        ret=num1+num2;
        break;
        case '-':
        ret=num2-num1;
        break;
        case '*':
        ret=num1*num2;
        break;
        case '/':
        ret=num2/num1;
        break;
        case '%':
        ret=num2%num1;
        break;
    }
    return ret;
}

void cal(stack_t *num,stack_t *sign){
    int cal_sign=sign->next->number;
    pop(sign);
    int num1=num->next->number;
    pop(num);
    int num2=num->next->number;
    pop(num);
    push(num,calculate(cal_sign,num1,num2),0);
}

int main(){
    stack_t *num=malloc(sizeof(stack_t));
    num->next=NULL;
    stack_t *sign=malloc(sizeof(stack_t));
    sign->next=NULL;
    int ch;
    int in_number=0;
    int number=0;
    int level;
    while((ch=getchar())!='='){
        if(ch>='0'&&ch<='9'){
            in_number=1;
            number=number*10+ch-'0';
        }else if(ch=='('||ch==')'||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'){
            level=calculateLevel(ch);
            if(in_number){
                push(num,number,0);//存数字默认level为0
                in_number=0;
                number=0;
            }
            if(sign->next==NULL){
                push(sign,ch,level);
            }else{
                int cal_sign;
                if(ch==')'){
                    while(sign->next->number!='('){
                        cal(num,sign);
                    }
                    pop(sign);//弹出左括号
                }else{
                    if(sign->next->level<level){
                        push(sign,ch,level);
                    }else{
                        while(sign->next!=NULL&&sign->next->level>=level){
                            cal_sign=sign->next->number;
                            if(cal_sign!='('){//如果弹出左括号
                                //什么操作也不进行
                                cal(num,sign);
                            }else{
                                break;
                            }
                        }
                        push(sign,ch,level);
                    }
                }
            }
        }else{
            if(in_number){
                push(num,number,0);
                in_number=0;
                number=0;
            }
        }
    }
    if(in_number){
        push(num,number,0);
    }
    while(sign->next!=NULL){
        cal(num,sign);
    }
    printf("%d",num->next->number);
    pop(num);
    free(num);
    free(sign);
    return 0;
}