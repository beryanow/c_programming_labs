#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *output = (char *) calloc(strlen(argv[1]), sizeof(char));
    char *stack = (char *) calloc(strlen(argv[1]), sizeof(char));
    int m = 0;
    int k = 0;
    int i = 0;

    /* creating Reverse Polish notation */
    while (i != strlen(argv[1])) {
        if ((argv[1][i] >= '0') && (argv[1][i] <= '9')) {
            int n = i;
            while ((argv[1][i] >= '0') && (argv[1][i] <= '9')) {
                i++;
            }
            output[m] = '(';
            m++;
            for (int z = n; z < i; z++) {
                output[m] = argv[1][z];
                m++;
            }
            output[m] = ')';
            m++;
        } else if ((argv[1][i] == '*') | (argv[1][i] == '/')) {
            while (1) {
                if ((stack[k - 1] == '*') | (stack[k - 1] == '/')) {
                    output[m] = stack[k - 1];
                    stack[k - 1] = argv[1][i];
                    m++;
                } else {
                    stack[k] = argv[1][i];
                    k++;
                    break;
                }
                k--;
            }
            i++;
        } else if ((argv[1][i] == '+') | (argv[1][i] == '-')) {
            while (1) {
                if ((stack[k - 1] == '*') | (stack[k - 1] == '/') | (stack[k - 1] == '+') | (stack[k - 1] == '-')) {
                    output[m] = stack[k - 1];
                    stack[k - 1] = argv[1][i];
                    m++;
                } else {
                    stack[k] = argv[1][i];
                    k++;
                    break;
                }
                k--;
            }
            i++;
        } else if (argv[1][i] == '(') {
            stack[k] = argv[1][i];
            k++;
            i++;
        } else if (argv[1][i] == ')') {
            int c = k - 1, z;
            while (stack[k] != '(') k--;
            for (z = c; z > k; z--) {
                output[m] = stack[z];
                m++;
                stack[z] = '\0';
            }
            stack[z] = '\0';
            k = z;
            i++;
        } else i++;
    }
    for (int i = k - 1; i >= 0; i--) {
        output[m] = stack[i];
        stack[i] = '\0';
        k--;
        m++;
    }
    /* end of creating Reverse Polish notation */

    /* result calculation */
    int result = 0;
    k = 0;
    int g;
    int final_result;
    while (output[strlen(output) - 1] != ')') {
        while (!((output[k] == '+') | (output[k] == '-') | (output[k] == '*') | (output[k] == '/'))) k++;
        char f = output[k];
        for (int x = k; x < strlen(output) - 1; x++) {
            output[x] = output[x + 1];
        }
        output[strlen(output) - 1] = '\0';
        k -= 2;
        int result1 = 0, result2 = 0;
        int h = 1;
        while (output[k] != '(') {
            result1 += (output[k] - '0') * h;
            h *= 10;
            for (int x = k; x < strlen(output) - 1; x++) {
                output[x] = output[x + 1];
            }
            output[strlen(output) - 1] = '\0';
            k--;
        }
        for (int x = k; x < strlen(output) - 2; x++) {
            output[x] = output[x + 2];
        }
        output[strlen(output) - 1] = '\0';
        output[strlen(output) - 1] = '\0';
        k -= 2;
        h = 1;
        while (output[k] != '(') {
            result2 += (output[k] - '0') * h;
            h *= 10;
            for (int x = k; x < strlen(output) - 1; x++) {
                output[x] = output[x + 1];
            }
            output[strlen(output) - 1] = '\0';
            k--;
        }
        switch (f) {
            case '+':
                result = result2 + result1;
                break;
            case '-':
                result = result2 - result1;
                break;
            case '*':
                result = result2 * result1;
                break;
            case '/':
                result = result2 / result1;
                break;
        }
        final_result = result;
        k++;
         while (result != 0) {
            for (int x = strlen(output); x > k; x--) {
                output[x] = output[x - 1];
            }
            output[k] = (char) (result % 10 + '0');
            result /= 10;
        }
    }
    printf("%d\n", final_result);
    /* end of result calculation */

    return 0;
}