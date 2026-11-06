/* Exercise 4-5: add sin, exp and pow to the postfix calculator.
   sin/exp take one operand; pow takes two (base exponent). */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
static double v[STACK_SIZE]; static int sp;
static int push(double x){ if(sp==STACK_SIZE){puts("error: stack full");return 0;} v[sp++]=x;return 1; }
static int pop(double *x){ if(!sp){puts("error: stack empty");return 0;} *x=v[--sp];return 1; }

int main(void){
    char line[1024], *t, *e; double x,a,b;
    puts("Postfix calculator with sin, exp, pow (angles for sin are radians).");
    while(fgets(line,sizeof line,stdin)){
        t=strtok(line," \t\r\n");
        while(t){
            x=strtod(t,&e);
            if(e!=t && !*e) push(x);
            else if(!strcmp(t,"sin") || !strcmp(t,"exp")){
                if(!pop(&a)) break;
                x=!strcmp(t,"sin")?sin(a):exp(a); push(x);
            } else if(!strcmp(t,"pow")){
                if(!pop(&b)||!pop(&a)) break;
                push(pow(a,b));
            } else if(strlen(t)==1 && strchr("+-*/",t[0])){
                if(!pop(&b)||!pop(&a)) break;
                if(t[0]=='+') x=a+b;
                else if(t[0]=='-') x=a-b;
                else if(t[0]=='*') x=a*b;
                else { if(b==0){puts("error: division by zero");break;} x=a/b; }
                push(x);
            } else { printf("error: unknown token %s\n",t); break; }
            t=strtok(NULL," \t\r\n");
        }
        if(sp==1) printf("%.10g\n",v[0]);
        else if(sp>1) printf("stack has %d values\n",sp);
        sp=0;
    }
    return 0;
}
