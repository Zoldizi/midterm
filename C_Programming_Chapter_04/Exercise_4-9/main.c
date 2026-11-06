/* Exercise 4-9: correctly support pushing EOF back onto the input.
   EOF is stored as a valid pushed-back value, separate from buffer state. */
#include <stdio.h>
static int pushed_char;
static int has_pushed_char;
static int getch(void){
    if(has_pushed_char){has_pushed_char=0;return pushed_char;}
    return getchar();
}
static void ungetch(int c){
    if(has_pushed_char) puts("ungetch: buffer already occupied");
    else {pushed_char=c;has_pushed_char=1;}
}
int main(void){
    int c;
    puts("EOF pushback test: the program pushes EOF once, reads it, then exits.");
    ungetch(EOF);
    c=getch();
    if(c==EOF) puts("Success: pushed-back EOF was read as EOF.");
    else puts("Error: expected EOF.");
    return 0;
}
