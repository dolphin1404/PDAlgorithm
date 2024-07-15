#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a, const void*b){
    return (strcmp((char*)a, (char*)b));
}

struct who{
    char name[21];
};
struct same{
    char who[21];
};

struct who name[1000001];
struct same who[500001];

int main(){
    int N, M;
    int cnt = 0;
    
    scanf("%d %d", &N, &M);
    
    for(int i=0;i<N+M;i++){
        scanf("%s", name[i].name);
    }
    
    qsort(name, N + M, sizeof(name[0]),cmp);

    for(int i=0;i < N + M;i++){
        if(strcmp(name[i].name, name[i+1].name) == 0){
            strcpy(who[cnt].who,name[i].name);
            i++;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for(int i = 0;i < cnt;i++)
        printf("%s\n", who[i].who);
    
}

