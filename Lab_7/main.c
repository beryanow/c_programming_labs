#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void to_do (char** stack, char** output_line, int* m, int* m1, int* y) {
    if ((*stack)[*m - 1] == '/') {
        int b = *m - 1;
        while (b != -1) {
            (*output_line)[*m1] = (*stack)[b];
            (*stack)[b] = '\0';
            b--;
            *y = -1;
            if (*stack[b] == '(') {
                *y = b + 1;
                *m1 = *m1 + 1;
                break;
            }
            *m1 = *m1 + 1;
        }
        if (*y != -1) {
            (*stack)[*y] = '*';
            *m = *y + 1;
        }
        else {
            (*stack)[0] = '*';
            *m = 1;
        }
    }
    else if ((*stack)[*m - 1] == '^') {
        int b = *m - 1;
        while (b != -1) {
            (*output_line)[*m1] = *stack[b];
            (*stack)[b] = '\0';
            *y = -1;
            if ((*stack)[b] == '(') {
                *y = b + 1;
                *m1 = *m1 + 1;
                break;
            }
            m1++;
        }
        if (*y != -1) {
            (*stack)[*y] = '*';
            *m = *y + 1;
        }
        else {
            (*stack)[0] = '*';
            *m = 1;
        }
    }
    else
    if ((*stack)[*m - 1] == '*') {
        int b = *m - 1;
        while (b != -1) {
            (*output_line)[*m1] = (*stack)[b];
            (*stack)[b] = '\0';
            b--;
            *y = -1;
            if ((*stack)[b] == '(') {
                *y = b + 1;
                *m1 = *m1 + 1;
                break;
            }
            *m1 = *m1 + 1;
        }
        if (*y != -1) {
            (*stack)[*y] = '*';
            *m = *y + 1;
        }
        else {
            (*stack)[0] = '*';
            *m = 1;
        }
    }
    else {
        (*stack)[*m] = '*'; //почему эта * магически преобразуется в   (видно в строке вывода)?
        *m1 = *m1 + 1;;
    }
}

char which_sign (char sign) {
    if (sign == '/') return '/';
    else if (sign == '*') return '*';
    else if (sign == '+') return '+';
    else if (sign == '-') return '-';
    else if (sign == '^') return '^';
    return sign;
}

int main(int argc, char* argv[]) {
    int string_size = strlen(argv[1]);
    char* output_line = (char*) malloc(string_size * sizeof(char));
    char* stack = (char*) malloc(string_size * sizeof(char));
    int m = 0; // stack
    int m1 = 0; // output_line
    int y;
    for (int i = 0; i < string_size; i++) {
        if ((argv[1][i]) != ' ') {
            if (which_sign(argv[1][i]) == '*') {
               to_do(&stack, &output_line, &m, &m1, &y);
            } else if (which_sign(argv[1][i]) == '/') {
                if (stack[m - 1] == '/') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '/';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '/';
                        m = 1;
                    }
                }
                else if (stack[m - 1] == '^') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '/';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '/';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '*') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '/';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '/';
                        m = 1;
                    }
                }
                else {
                    stack[m] = argv[1][i];
                    m++;
                }
            } else if (which_sign(argv[1][i]) == '+') {
                if (stack[m - 1] == '/') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '+';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '+';
                        m = 1;
                    }
                }
                else if (stack[m - 1] == '^') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '+';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '+';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '*') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '+';
                        m1++;
                        m = y + 1;
                    }
                    else {
                        stack[0] = '+';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '+') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '+';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '+';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '-') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '+';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '+';
                        m = 1;
                    }
                }
                else {
                    stack[m] = argv[1][i];
                    m++;
                }
            } else if (which_sign(argv[1][i]) == '-') {
                if (stack[m - 1] == '-') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '-';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '-';
                        m = 1;
                    }
                }
                else if (stack[m - 1] == '^') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '-';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '-';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '+') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '-';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '-';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '*') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '-';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '-';
                        m = 1;
                    }
                }
                else
                if (stack[m - 1] == '/') {
                    int b = m - 1;
                    while (b != -1) {
                        output_line[m1] = stack[b];
                        stack[b] = '\0';
                        b--;
                        y = -1;
                        if (stack[b] == '(') {
                            y = b + 1;
                            m1++;
                            break;
                        }
                        m1++;
                    }
                    if (y != -1) {
                        stack[y] = '-';
                        m = y + 1;
                    }
                    else {
                        stack[0] = '-';
                        m = 1;
                    }
                }
                else {
                    stack[m] = argv[1][i];
                    m++;
                }
            } else if (which_sign(argv[1][i]) == '^') {
                stack[m] = '^';
                m++;
            } else if (argv[1][i] == '(') {
                stack[m] = '(';
                m++;
            } else if (argv[1][i] == ')') {
                int z = m - 1;
                while (z >= 0) {
                    if (stack[z] == '(') {
                        int k = z;
                        z = m - 1;
                        while (z != k) {
                            output_line[m1] = stack[z];
                            z--;
                            m1++;
                        }
                        for (int e = k; e <= m; e++) {
                            stack[e] = '\0';
                        }
                        m = k;
                        break;
                    }
                    z--;
                }
            }
            else if ((argv[1][i] >= '0') && (argv[1][i] <= '9')) {
                output_line[m1] = argv[1][i];
                m1++;
            }
        }
    }
    while (stack[0] != '\0') {
        m--;
        output_line[m1] = stack[m];
        stack[m] = '\0';
        m1++;
    }
    for (int i = 0; i < m1; i++) printf("%c ", output_line[i]);
    return 0;
}
