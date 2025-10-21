#include <ctype.h>
#include <stdio.h>

long long addOp(long long  num1, long long  num2);
long long subOp(long long  num1, long long  num2);
long long mulOp(long long  num1, long long  num2);
long long divOp(long long  num1, long long  num2);

int main(void) {

    long long num1 = 0, num2 = 0;
    char op = '\0';
    long long result = 0;
    char input = '\0';

    printf(" --------------- \n");
    printf("| 1 | 2 | 3 | + | \n");
    printf("|---|---|---|---| \n");
    printf("| 4 | 5 | 6 | - | \n");
    printf("|---|---|---|---|\n");
    printf("| 7 | 8 | 9 | * | \n");
    printf("|---|---|---|---| \n");
    printf("| C | 0 | = | / | \n");
    printf(" --------------- \n");

    do {

        while (1) {
            inizio:
            printf("First number:");
            if (scanf("%lld", &num1) == 1) {
                second_num:
                printf("Second number:");
                if (scanf("%lld", &num2) == 1) {
                    break;
                }
                while (getchar() != '\n');
                printf("Invalid number\n");
                goto second_num;
            }
            while (getchar() != '\n');
            printf("Invalid number\n");
        }

        while (1) {
            printf("Select the operation (+, -, *, /, C): ");
            scanf(" %c", &op);
            op = toupper(op);
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == 'C') {
                break;
            }
            printf("Invalid input\n");
        }

        switch (op) {
            case '+':
                result = addOp(num1, num2);
                printf("The result is: %lld\n", result);
                break;
            case '-':
                result = subOp(num1, num2);
                printf("The result is: %lld\n", result);
                break;
            case '*':
                result = mulOp(num1, num2);
                printf("The result is: %lld\n", result);
                break;
            case '/':
                result = divOp(num1, num2);
                printf("The result is: %lld\n", result);
                break;
            case 'C':
                num1 = 0;
                num2 = 0;
                goto inizio;
        }

        while (1) {
            printf("Wanna keep going? (y/n): ");
            scanf(" %c", &input);
            input = toupper(input);
            switch (input) {
                case 'N':
                    return 0;
                case 'Y':
                    goto inizio;
            }
        }

    }while (1);
}

long long addOp(long long num1, long long num2) {
    return num1 + num2;
}

long long subOp(long long num1, long long num2) {
    return num1 - num2;
}

long long mulOp(long long num1, long long num2) {
    return num1 * num2;
}

long long divOp(long long num1, long long num2) {
    return num1 / num2;
}