#include <stdio.h>
#include <stdlib.h>

struct line{
    int data;
    struct line *next;
};
typedef struct line line_t;

void push(int data,line_t **tail){
    line_t *new=malloc(sizeof(line_t));
    new->data=data;
    new->next=NULL;
    (*tail)->next=new;
    *tail=(*tail)->next;
}

void pophead(line_t *l){
    line_t *delete=l->next;
    l->next=delete->next;
    free(delete);
}
void poptail(line_t **tail,line_t *l){
    line_t *temp=l;
    while(temp->next!=*tail){
        temp=temp->next;
    }
    line_t *delete=*tail;
    *tail=temp;
    free(delete);
}

int core(line_t *l,line_t **tail,int *num,int n,int k){
    long long prefix[n+1];
    int sum=0;
    prefix[0]=sum;
    for(int i=0;i<n;i++){
        sum+=num[i];
        prefix[i+1]=sum;
    }
    int min=-1;
    for(int i=0;i<n+1;i++){
        if(i==0){
            push(i,tail);
        }else{
            while(l->next!=NULL&&prefix[i]-prefix[l->next->data]>=k){
                min=i-l->next->data;
                pophead(l);
            }
            while(l->next!=NULL&&prefix[i]<=prefix[(*tail)->data]){
                poptail(tail,l);
            }
            push(i,tail);
        }
    }
    return min;
}

int main(){
    line_t *l=malloc(sizeof(line_t));
    l->next=NULL;
    line_t *tail=l;
    int n=0;
    int k;
    int cap=4;
    int x;//临时储存
    int *num=malloc(sizeof(int)*cap);
    while(scanf("%d",&x)==1){
        if(n>=cap){
            cap*=2;
            num=realloc(num,sizeof(int)*cap);
        }
        num[n]=x;
        n++;
    }
    n--;
    k=num[n];
    printf("%d",core(l,&tail,num,n,k));
}