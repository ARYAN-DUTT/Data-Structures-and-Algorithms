#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char expr[100];
    int stack[100];
    int top = -1;

    printf("Enter postfix expression: ");
    if (!fgets(expr, sizeof expr, stdin)) return 0;
    size_t len = strlen(expr);
    if (len > 0 && expr[len-1] == '\n') expr[len-1] = '\0';

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ' ') {
            continue;
        } else if (isdigit((unsigned char)expr[i])) {
            int num = 0;
            while (isdigit((unsigned char)expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        } else {
            char op = expr[i];
            if (top < 1) {
                printf("Error: insufficient operands for '%c'\n", op);
                return 1;
            }
            int val2 = stack[top--];
            int val1 = stack[top--];
            int res = 0;
            switch (op) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/':
                    if (val2 == 0) {
                        printf("Error: division by zero\n");
                        return 1;
                    }
                    res = val1 / val2; break;
                default:
                    printf("Error: unknown operator '%c'\n", op);
                    return 1;
            }
            stack[++top] = res;
        }
    }

    if (top != 0) {
        printf("Error: invalid expression (stack has %d elements)\n", top + 1);
        return 1;
    }

    printf("Result: %d\n", stack[top]);
    return 0;
}