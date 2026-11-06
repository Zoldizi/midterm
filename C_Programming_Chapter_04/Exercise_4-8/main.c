/* Exercise 4-8: getch/ungetch with at most one pushed-back character. */
#include <stdio.h>
static int pushed = 0;
static int has_pushed = 0;
static int getch(void){if(has_pushed){has_pushed=0;return pushed;}return getchar();}
static void ungetch(int c){
    if(has_pushed) puts("ungetch: too many characters");
    else {pushed=c;has_pushed=1;}
}
int main(void){
    int c, next;
    puts("Type characters. This demo reads one character, pushes it back, then reads it again.");
    while((c=getch())!=EOF){
        ungetch(c);
        next=getch();
        putchar(next);
    }
    return 0;
}
