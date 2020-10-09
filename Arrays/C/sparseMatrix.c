#include<stdio.h>
#include<stdlib.h>
struct Elements {
    int i;
    int j;
    int x;
};
struct Sparse{
    int m;
    int n;
    int num;
    struct Elements *e;
};
void create(struct Sparse *s){
    printf("Enter the dimensions:\n");
    printf("value of m = ");
    scanf("%d",&s->m);
    printf("value of n = ");
    scanf("%d",&s->n);
    printf("Enter the number of Non-Zero elements = ");
    scanf("%d",&s->num);
    s->e = (struct Elements*) malloc(s->num * sizeof(struct Elements));
    printf("Enter all the Non-zero Elements:\n");
    for (int k = 0; k < s->num; k++){
        printf("Enter for Value %d:\n",k+1);
        printf("value of i = ");
        scanf("%d",&s->e[k].i);
        printf("value of j = ");
        scanf("%d",&s->e[k].j);
        printf("value of the Non-Zero element = ");
        scanf("%d",&s->e[k].x);
    }
}
void display(struct Sparse s){
    int i,j,k=0;
    for ( i = 0; i < s.m; i++){
        for ( j = 0; j < s.n; j++){
            if((i == s.e[k].i)&&(j == s.e[k].j)){
                printf("%d\t",s.e[k++].x);
            }
            else
                printf("0\t");
        }
        printf("\n");       
    }
}
int main(){
    struct Sparse s;
    create(&s);
    display(s);
    return 0;
}