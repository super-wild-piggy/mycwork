#include <stdio.h>
#include <stdlib.h>
//单调栈解决左右边界问题

struct linknode{
    int height;
    int idx;
    struct linknode *next;
};
typedef struct linknode LinkStNode;

void push(LinkStNode **s,int data,int idx,LinkStNode **top,LinkStNode **top_prev){
    if(*s==NULL){//若栈为空
        LinkStNode *new=malloc(sizeof(LinkStNode));
        new->height=data;
        new->idx=idx;
        *s=new;
        *top=*s;
        *top_prev=NULL;
    }else{
        LinkStNode *new=malloc(sizeof(LinkStNode));
        new->height=data;
        new->idx=idx;
        new->next=NULL;
        (*top)->next=new;
        *top_prev=*top;
        *top=(*top)->next;
    }
}

void pop(LinkStNode **s,LinkStNode **top,LinkStNode **top_prev){
    if(*top_prev==NULL){
        free(*top);
        *top=NULL;
        *s=NULL;
    }else{
        LinkStNode *temp=*s;
        if(temp==*top_prev){
            free(*top);
            *top=*top_prev;
            (*top)->next=NULL;
            *top_prev=NULL;
        }else{
            while(temp->next!=*top_prev){
                temp=temp->next;
            }
            free(*top);
            *top=*top_prev;
            (*top)->next=NULL;
            *top_prev=temp;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int rectangle_height[n+1];//末尾加一个0 使得所有栈里的数都能出来
    for(int i=0;i<n;i++){
        scanf("%d",&rectangle_height[i]);
    }
    rectangle_height[n]=0;
    LinkStNode *s=NULL;
    LinkStNode *top=NULL;
    LinkStNode *top_prev=NULL;
    int area;
    int max_area=0;
    int idx_left;//左边界
    int idx_right;//右边界
    for(int i=0;i<n+1;i++){
        if(top==NULL){
            push(&s,rectangle_height[i],i,&top,&top_prev);
        }else if(rectangle_height[i]<top->height){
            //单调递增栈将要被破坏
            //此时计算面积
            idx_right=i;
            if(top_prev!=NULL){
                idx_left=top_prev->idx;
            }else{//栈里只有一个元素 说明这个元素前面都比他大
                idx_left=-1;
            }
            area=top->height*(idx_right-idx_left-1);
            if(area>max_area){
                max_area=area;
            }
            i--;
            pop(&s,&top,&top_prev);
        }else{
            push(&s,rectangle_height[i],i,&top,&top_prev);
        }
    }
    printf("%d",max_area);
    free(s);
    return 0;
}