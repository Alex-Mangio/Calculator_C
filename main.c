#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

double addOp(double  num1, double  num2);
double subOp(double  num1, double  num2);
double mulOp(double  num1, double  num2);
double divOp(double  num1, double  num2);
double equalOp(double *arr1, char *arr2, int size);

int main () {
    //double num1 = 0, num2 = 0;
    double num;
    char op = '\0';
    char input = '\0';
    char *ops = NULL;
    double *arr = NULL;
    int sizeChar = 0;
    int nChar = 0;
    int sizeInt = 0;
    int nInt = 0;


    printf(" --------------- \n");
    printf("| 1 | 2 | 3 | + | \n");
    printf("|---|---|---|---| \n");
    printf("| 4 | 5 | 6 | - | \n");
    printf("|---|---|---|---|\n");
    printf("| 7 | 8 | 9 | * | \n");
    printf("|---|---|---|---| \n");
    printf("| C | 0 | = | / | \n");
    printf(" --------------- \n");


    char continueInput = 'Y';
    while (continueInput == 'Y') {

        free(arr);
        free(ops);
        arr = NULL;
        ops = NULL;
        sizeInt = nInt = 0;
        sizeChar = nChar = 0;

        while (1) {
            printf("Enter a number: ");
            if (scanf(" %lf", &num) != 1) {
                printf("Input not valid\n");
                while (getchar() != '\n');
                continue;
            }

            if (nInt == sizeInt) {
                sizeInt = (sizeInt == 0) ? 4 : sizeInt * 2;
                double *temp = realloc(arr, sizeInt * sizeof(double));
                if (!temp) {
                    printf("Error allocation memory\n");
                    free(arr);
                    free(ops);
                    return 1;
                }
                arr = temp;
            }
            arr[nInt++] = num;

            while (1) {
                printf("Select the operation (+, -, *, /, C, =): ");
                if (scanf(" %c", &op) != 1) {
                    printf("Input not valid\n");
                    while (getchar() != '\n');
                    continue;
                }

                op = toupper(op);

                if (op == 'C') {
                    nInt = nChar = 0;
                    break;
                }

                if (op != '+' && op != '-' && op != '*' && op != '/' && op != '=') {
                    printf("Operator not valid\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (nChar == sizeChar) {
                    sizeChar = (sizeChar == 0) ? 4 : sizeChar * 2;
                    char *temp2 = realloc(ops, sizeChar * sizeof(char));
                    if (!temp2) {
                        printf("Error allocation memory\n");
                        free(arr);
                        free(ops);
                        return 1;
                    }
                    ops = temp2;
                }
                ops[nChar++] = op;
                break;
            }

            if (nChar > 0 && ops[nChar - 1] == '=') {
                break;
            }

            if (op == 'C') {
                continue;
            }
        }

        printf("The result is: %.2f\n", equalOp(arr, ops, nChar));

        while (1) {
            printf("Do you want to keep going? (Y/N): ");
            if (scanf(" %c", &continueInput) != 1) {
                while (getchar() != '\n');
                continue;
            }
            continueInput = toupper(continueInput);
            if (continueInput == 'Y' || continueInput == 'N') break;

            printf("Input not valid\n");
            while (getchar() != '\n');
        }
    }

    free(arr);
    free(ops);
    return 0;
}

double addOp(double num1, double num2) {
    return num1 + num2;
}

double subOp(double num1, double num2) {
    return num1 - num2;
}

double mulOp(double num1, double num2) {
    return num1 * num2;
}

double divOp(double num1, double num2) {
    if (num2 == 0) {
        return 0;
    }
    return num1 / num2;
}

double equalOp(double *arr1, char *arr2, int size) {
    double result = arr1[0];
    for (int i = 0; i < size; i++) {
            switch (arr2[i]) {
                case '+':
                    result = addOp(result, arr1[i + 1]);
                    break;
                case '-':
                    result = subOp(result, arr1[i + 1]);
                    break;
                case '*':
                    result = mulOp(result, arr1[i + 1]);
                    break;
                case '/':
                    result = divOp(result, arr1[i + 1]);
                    break;
                case '=':
                    return result;
            }
    }
        return result;
}
