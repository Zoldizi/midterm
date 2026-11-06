/* Exercise 4-7: ungets(s) pushes an entire string back onto input.
   Demonstration: the calculator reads a line, then ungets it into its
   character input stream and tokenizes it with getch(). */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
static char input[BUFSIZE]; static size_t bp;
static int getch(void){return bp ? (unsigned char)input[--bp] : getchar();}
static void ungetch(int c){if(bp<BUFSIZE) input[bp++]=(char)c; else puts("error: input buffer full");}
static void ungets(const char s[]){
    size_t n=strlen(s);
    while(n>0) ungetch((unsigned char)s[--n]);
}
int main(void){
    char line[1024], token[128]; int c,i; double value;
    puts("Enter a line of numbers and operators; each line is evaluated.");
    while(fgets(line,sizeof line,stdin)){
        ungets(line); value=0.0; i=0;
        while((c=getch())!=EOF && c!='\n'){
            if(isspace(c)) continue;
            if(isdigit(c)||c=='.'||(c=='-' && i==0)){
                if(i<127) token[i++]=(char)c;
                while((c=getch())!=EOF && (isdigit(c)||c=='.')) if(i<127)token[i++]=(char)c;
                token[i]='\0'; if(c!=EOF)ungetch(c);
                value+=strtod(token,NULL); i=0;
            }
        }
        printf("Sum of numeric operands: %.10g\n",value);
        bp=0;
    }
    return 0;
}
