#include <stdio.h>

int main(void)
{
    // char *s = "\n";
    char *s = "\x01\x02\a\v\b\f\r\n";
    int n = printf ("%s", s);
    // int n = printf ("sldfjj\0dslkfjsdf\n");
    // int n = printf ("\001\002\007\v\010\f\r\n");
    printf ("\nn: %d\n",n);
    return (0);
}