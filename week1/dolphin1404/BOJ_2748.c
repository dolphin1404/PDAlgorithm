#include <stdio.h>


long long int fibo(int N) {
  long long int n[91];
  n[0] = 0;
  n[1] = 1;
  for (int i = 2; i <= N; i++) {
    n[i] = n[i - 1] + n[i - 2];
  }
  return n[N];
}

/* recursion
long long int fibo(int N){
  if(N<3) return 1;
  return fibo(N-1) + fibo(N-2);
}
*/

int main(){
    int N, result;
    scanf("%d", &N);
    printf("%lld", fibo(N));
}

