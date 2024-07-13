#include <stdio.h>

int N, S, ans;
int num[20];

void subseq(int idx, int sum) {
    sum += num[idx];
    
    if(idx >= N)
        return;

    if(sum == S)
        ans += 1;
    
    subseq(idx + 1, sum - num[idx]);
    subseq(idx + 1, sum);

}

int main() {

    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);

    subseq(0, 0);
    printf("%d", ans);

    return 0;
}