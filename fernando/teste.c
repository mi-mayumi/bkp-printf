#include <stdio.h>
#include <stdarg.h>

// Função variádica que soma números inteiros
int main()
{
    int result = printf("Sentence to know how many %s\n", "characters were written");
    
    printf("%d characters were written", result);
}