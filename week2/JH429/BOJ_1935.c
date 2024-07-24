#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100

int sp = -1;
double stack[MAX_SIZE];


int main() {
    int N, idx = 0;
    double ans = 0;
    int val[26];
    char postfix[MAX_SIZE];

    scanf("%d", &N);
    scanf("%s", postfix);

    for(int i = 0; i < N; i++)
        scanf("%d", val + i);

    for(int i = 0; postfix[i] != '\0'; i++) {
        if(isalpha(postfix[i])) 
            stack[++sp] = val[postfix[i] - 'A'];

        

        else {
            double op1 = stack[sp--];
            double op2 = stack[sp--];
            switch (postfix[i]) {
                case '+':
 
                    ans = op2 + op1;
                    stack[++sp] = ans;
                    break;

                case '-':
                    ans = op2 - op1;
                    stack[++sp] = ans;
                    break;

                case '*':
                    ans = op2 * op1;
                    stack[++sp] = ans;
                    break;

                case '/':
                    ans = op2 / op1;
                    stack[++sp] = ans;
                    break;
            }
        }
    }

    printf("%.2lf", stack[sp]);

    return 0;
}