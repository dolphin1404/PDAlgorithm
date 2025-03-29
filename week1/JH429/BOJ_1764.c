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
    int n, m, i, j, c = 0;
    
    scanf("%d %d", &n, &m);
    
    for(i=0;i<n+m;i++){
        scanf("%s", name[i].name);
    }
    
    qsort(name, n+m, sizeof(name[0]),cmp);

    for(i=0;i<n+m;i++){
        if(strcmp(name[i].name, name[i+1].name) == 0){
            strcpy(who[c].who,name[i].name);
            i++;
            c++;
        }
    }
    printf("%d\n", c);
    for(i=0;i<c;i++)
        printf("%s\n", who[i].who);
    
}

