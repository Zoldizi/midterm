/* Exercise 4-10: line-oriented postfix calculator.
   fgets reads a complete line; no getch/ungetch pushback is needed. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
static double stack[STACK_SIZE]; static int sp;
static int push(double x){if(sp==STACK_SIZE){puts("error: stack full");return 0;}stack[sp++]=x;return 1;}
static int pop(double *x){if(!sp){puts("error: stack empty");return 0;}*x=stack[--sp];return 1;}
int main(void){
    char line[1024],*t,*e; double x,a,b;
    puts("Line-based postfix calculator (+ - * /). Enter one expression per line.");
    while(fgets(line,sizeof line,stdin)){
        sp=0; t=strtok(line," \t\r\n");
        while(t){
            x=strtod(t,&e);
            if(e!=t && !*e) push(x);
            else if(strlen(t)==1 && strchr("+-*/",t[0])){
                if(!pop(&b)||!pop(&a))break;
                if(t[0]=='+')x=a+b; else if(t[0]=='-')x=a-b; else if(t[0]=='*')x=a*b;
                else {if(b==0){puts("error: division by zero");break;}x=a/b;}
                push(x);
            } else {printf("error: unknown token %s\n",t);break;}
            t=strtok(NULL," \t\r\n");
        }
        if(sp==1)printf("%.10g\n",stack[0]);
        else if(sp>1)printf("error: expression leaves %d values\n",sp);
        else puts("error: no result");
    }
    return 0;
}
