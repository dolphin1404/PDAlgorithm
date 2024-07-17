#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
    long long num1 = *(long long*)a; // long long타입의 값으로 변환하기 위해 (long long*)를 사용, const void*는 상수 포인터로, 가리키는 값을 변경할 수 없도록 만들기 위함
    long long num2 = *(long long*)b; // (long long*)은 void* 포인터에서 변환해주기위함. -> *을 사용해서 포인터가 가리키고 있는 실제 값을 참조함, 이러한 과정을 이용하는 이유는 실제 데이터가 어떤 타입인지 알 수 없기때문에 직접 값을 참조하거나 비교할 수 없기때문
    if(num1 > num2) return 1;
    if(num1 < num2) return -1;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    long long* array = malloc(n * sizeof(long long));
 
    for(int i=0;i<n;i++){
        scanf("%lld", &array[i]);
    }
    qsort(array, n, sizeof(long long), compare);
    
    long long most_freq_card = array[0];
    int max_count = 1, current_count = 1;

    for(int i=1;i<n;i++){
        if(array[i] == array[i-1]){
            current_count++;
        }else{
            if(current_count > max_count){
                max_count = current_count;
                most_freq_card = array[i-1];
            }
            current_count = 1;
        }
    }
    if(current_count > max_count){ //가장 빈번한 요소가 마지막일때 예외처리 -> 마지막은 else에 들어가서 most_freq_card를 지정해주지 않음.
        most_freq_card = array[n-1];
    }
    printf("%lld\n", most_freq_card);

    free(array);


}