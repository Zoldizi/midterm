/* Exercise 4-4: postfix calculator stack commands.
   Commands: p=print top, d=duplicate top, s=swap top two, c=clear stack.
   Operators: + - * / */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
static double val[STACK_SIZE];
static int sp;

static int push(double x) {
    if (sp == STACK_SIZE) { puts("error: stack full"); return 0; }
    val[sp++] = x; return 1;
}
static int pop(double *x) {
    if (!sp) { puts("error: stack empty"); return 0; }
    *x = val[--sp]; return 1;
}
int main(void) {
    char line[1024], *t, *e; double x, a, b;
    puts("Postfix calculator: p print, d duplicate, s swap, c clear; Ctrl+D to quit.");
    while (fgets(line, sizeof line, stdin)) {
        t = strtok(line, " \t\r\n");
        while (t) {
            x = strtod(t, &e);
            if (e != t && !*e) push(x);
            else if (!strcmp(t, "p")) {
                if (sp) printf("%.10g\n", val[sp-1]); else puts("error: stack empty");
            } else if (!strcmp(t, "d")) {
                if (sp) push(val[sp-1]); else puts("error: stack empty");
            } else if (!strcmp(t, "s")) {
                if (sp < 2) puts("error: need two stack values");
                else { x=val[sp-1]; val[sp-1]=val[sp-2]; val[sp-2]=x; }
            } else if (!strcmp(t, "c")) sp = 0;
            else if (strlen(t)==1 && strchr("+-*/", t[0])) {
                if (!pop(&b) || !pop(&a)) break;
                if (t[0]=='+' ) x=a+b;
                else if (t[0]=='-') x=a-b;
                else if (t[0]=='*') x=a*b;
                else { if (b==0) { puts("error: division by zero"); break; } x=a/b; }
                push(x);
            } else { printf("error: unknown command %s\n", t); break; }
            t = strtok(NULL, " \t\r\n");
        }
        if (sp) printf("top = %.10g\n", val[sp-1]);
    }
    return 0;
}
