/* Exercise 4-6: variables a-z and last printed value.
   Assignment syntax: 12.5 a = ; then use a in later expressions.
   'v' pushes the most recently printed result. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
static double val[STACK_SIZE], vars[26], last_printed;
static int sp, initialized[26];
static int push(double x){if(sp==STACK_SIZE){puts("error: stack full");return 0;}val[sp++]=x;return 1;}
static int pop(double *x){if(!sp){puts("error: stack empty");return 0;}*x=val[--sp];return 1;}

int main(void){
    char line[1024],*t,*e; double x,a,b; int k;
    puts("Variables a-z; assignment: 12 a = ; 'v' recalls last printed value.");
    while(fgets(line,sizeof line,stdin)){
        t=strtok(line," \t\r\n");
        while(t){
            x=strtod(t,&e);
            if(e!=t && !*e) push(x);
            else if(strlen(t)==1 && t[0]>='a' && t[0]<='z'){
                k=t[0]-'a';
                if(initialized[k]) push(vars[k]); else printf("error: variable %c is undefined\n",t[0]);
            } else if(!strcmp(t,"v")) push(last_printed);
            else if(!strcmp(t,"=")){
                if(!pop(&a)||!sp){puts("error: assignment needs value and variable");break;}
                /* Assignment target is represented by a preceding token such as 'a=' in this simple syntax. */
                puts("error: use a= after the value (example: 12 a=)");
            } else if(strlen(t)==2 && t[1]=='=' && t[0]>='a' && t[0]<='z'){
                if (!pop(&a))
                    break;
                k = t[0] - 'a';
                vars[k] = a;
                initialized[k] = 1;
            } else if(strlen(t)==1 && strchr("+-*/",t[0])){
                if(!pop(&b)||!pop(&a))break;
                if(t[0]=='+')x=a+b; else if(t[0]=='-')x=a-b; else if(t[0]=='*')x=a*b;
                else {if(b==0){puts("error: division by zero");break;}x=a/b;}
                push(x);
            } else if(!strcmp(t,"?")){
                if (!pop(&last_printed))
                    break;
                printf("%.10g\n", last_printed);
            } else {printf("error: unknown token %s\n",t);break;}
            t=strtok(NULL," \t\r\n");
        }
        if(sp==1){last_printed=val[0];printf("%.10g\n",last_printed);sp=0;}
        else if(sp>1){printf("error: %d values left on stack\n",sp);sp=0;}
    }
    return 0;
}
