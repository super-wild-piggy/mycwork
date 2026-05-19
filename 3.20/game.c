#include <stdio.h>
#include <stdlib.h>
#define EXPAND 200

void push(int *deck,int *tail,int data,int *count){
    if(*count*EXPAND<=*tail){
        (*count)++;
        deck=realloc(deck,(*count)*EXPAND);
    }
    deck[*tail]=data;
    (*tail)++;
}

int pop(int *deck,int *head){
    int ret=deck[*head];
    (*head)++;
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    int *deck;
    int *deck1;
    deck=malloc(EXPAND*sizeof(int));
    deck1=malloc(EXPAND*sizeof(int));
    int count=1;
    for(int i=0;i<n;i++){
        scanf("%d",&deck[i]);
    }
    int head=0;
    int tail=n;
    int head1=0;
    int tail1=0;
    int index[14];
    int number=0;
    for(int i=0;i<14;i++){
        index[i]=0;
    }
    while(head!=tail){
        int data=pop(deck,&head);
        number++;
        if(index[data]==0){
            index[data]++;
            push(deck1,&tail1,data,&count);
        }else{
            tail1--;
            index[data]=0;
            while(deck1[tail1]!=data){
                int data1=pop(deck1,&tail1);
                tail1=tail1-2;
                index[data1]--;
                push(deck,&tail,data1,&count);
            }
        }   
    }
    printf("%d",number);
    free(deck);
    free(deck1);
}