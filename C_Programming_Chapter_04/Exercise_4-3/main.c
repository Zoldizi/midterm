/* Exercise 4-3: postfix calculator with modulus and negative numbers.
   Build: gcc -std=c99 -Wall -Wextra -pedantic main.c -lm */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

static double stack[STACK_SIZE];
static int sp;

static int push(double x)
{
    if (sp >= STACK_SIZE) { fprintf(stderr, "error: stack full\n"); return 0; }
    stack[sp++] = x;
    return 1;
}
static int pop(double *x)
{
    if (sp <= 0) { fprintf(stderr, "error: stack empty\n"); return 0; }
    *x = stack[--sp];
    return 1;
}

int main(void)
{
    char line[1024], *tok, *end;
    double a, b, value;
    puts("Postfix calculator: + - * / %; negative numbers supported.");
    puts("Enter one expression per line; Ctrl+D to quit.");
    while (fgets(line, sizeof line, stdin)) {
        sp = 0;
        tok = strtok(line, " \t\r\n");
        while (tok) {
            value = strtod(tok, &end);
            if (end != tok && *end == '\0') {
                if (!push(value)) break;
            } else if (strlen(tok) == 1 && strchr("+-*/%", tok[0])) {
                if (!pop(&b) || !pop(&a)) break;
                switch (tok[0]) {
                    case '+': value = a + b; break;
                    case '-': value = a - b; break;
                    case '*': value = a * b; break;
                    case '/':
                        if (b == 0.0) { fprintf(stderr, "error: division by zero\n"); goto next_line; }
                        value = a / b; break;
                    default:
                        if (b == 0.0) { fprintf(stderr, "error: modulus by zero\n"); goto next_line; }
                        value = fmod(a, b); break;
                }
                if (!push(value)) break;
            } else {
                fprintf(stderr, "error: unknown token '%s'\n", tok);
                break;
            }
            tok = strtok(NULL, " \t\r\n");
        }
        if (sp == 1) printf("%.10g\n", stack[0]);
        else if (sp > 1) fprintf(stderr, "error: expression leaves %d values on stack\n", sp);
        else fprintf(stderr, "error: no result\n");
next_line:
        ;
    }
    return 0;
}
