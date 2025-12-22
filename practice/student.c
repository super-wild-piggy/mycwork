#include <stdio.h>

struct stdinfo{
    char no[20];
    char name[10];
    float score[6];
    float aver,total;
};

void input(struct stdinfo *p,int n){
    int j;
    for(j=0;j<n;j++){
        printf("Please enter %d's information:\n",j+1);
        printf("Student id:");
        scanf("%s",p->no);
        printf("Name:");
        scanf("%s",p->name);
        printf("Grades in 6 courses:");
        for(int i=0;i<6;i++){
            scanf("%f",&p->score[i]);
        }
        p->total=0;
        for(int i=0;i<6;i++){
            p->total+=p->score[i];
        }
        p->aver=p->total/6;
        p++;
    }

}

void output(struct stdinfo *p,int n){
    printf("Id\t");
    printf("Name\t");
    printf("Score1\t");
    printf("Score2\t");
    printf("Score3\t");
    printf("Score4\t");
    printf("Score5\t");
    printf("Score6\t");
    printf("Total\t");
    printf("Average\t");
    printf("\n");
    for(int j=0;j<n;j++){
        printf("%s\t",p->no);
        printf("%s\t",p->name);
        for(int i=0;i<6;i++){
            printf("%.2f\t",p->score[i]);
        }
        printf("%.2f\t",p->total);
        printf("%.2f\t",p->aver);
        printf("\n");
        p++; 
    }
}

void calculat(struct stdinfo *p,int n,int *nopass,int *good){
    *good=0;
    *nopass=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            if(p->score[j]>=90){
                (*good)++;
            }
            if(p->score[j]<60){
                (*nopass)++;
            }
        }
        p++;
    }
}

int main(){
    int good,nopass,n;
    printf("Please enter students number:");
    scanf("%d",&n);
    struct stdinfo information[n];
    struct stdinfo *p=information;
    input(p,n);
    output(p,n);
    calculat(p,n,&nopass,&good);
    printf("Number of flunks %d\n",nopass);
    printf("Number of good %d\n",good);
}