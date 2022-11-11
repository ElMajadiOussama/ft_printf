#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float   float_sum(int n, ...)
{
    int i = 0;
    float sum = 0.0;
    va_list args;
    va_start (args, n);
    while (i < n)
    {
        sum += (float) va_arg(args, double);
        i++;
    }
    va_end(args);
    return sum;

}
int main(void)
{
    float f = float_sum (1, 2.0, 2.0, 3.0);

    printf("%f.\n", (double) f);
    return EXIT_SUCCESS;
}