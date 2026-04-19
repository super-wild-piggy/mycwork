#include <stdio.h>
#include <stdlib.h>
//单调栈解决左右边界问题

struct linknode{
    int height;
    int idx;
    struct linknode *next;
};
typedef struct linknode LinkStNode;

void push(LinkStNode *s,int data,int idx){
    if(s->next==NULL){//栈为空
        LinkStNode *new=malloc(sizeof(LinkStNode));
        new->height=data;
        new->idx=idx;
        new->next=NULL;
        s->next=new;
    }else{
        LinkStNode *new=malloc(sizeof(LinkStNode));
        new->height=data;
        new->idx=idx;
        new->next=s->next;
        s->next=new;
    }
}

void pop(LinkStNode *s){
    LinkStNode *delete=s->next;
    s->next=delete->next;
    free(delete);
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
    s=malloc(sizeof(LinkStNode));
    s->next=NULL;//初始化栈
    int area;
    int max_area=0;
    int idx_left;//左边界
    int idx_right;//右边界
    for(int i=0;i<n+1;i++){
        if(s->next==NULL){
            push(s,rectangle_height[i],i);
        }else if(rectangle_height[i]<s->next->height){
            //单调递增栈将要被破坏
            //此时计算面积
            idx_right=i;
            if(s->next->next!=NULL){
                idx_left=s->next->next->idx;
            }else{//栈里只有一个元素 说明这个元素前面都比他大
                idx_left=-1;
            }
            area=s->next->height*(idx_right-idx_left-1);
            if(area>max_area){
                max_area=area;
            }
            i--;
            pop(s);
        }else{
            push(s,rectangle_height[i],i);
        }
    }
    printf("%d",max_area);
    free(s);
    return 0;
}