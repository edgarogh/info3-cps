#include "stdarg.h"
#include "stdio.h"

double min(unsigned int n, ...) {
    va_list ap;
    va_start(ap, n);

    float cmin = va_arg(ap, double);
    for (unsigned int i = 1; i < n; i++) {
        float f = va_arg(ap, double);
        if (f < cmin) cmin = f;
    }

    va_end(ap);

    return cmin;
}

int main() {
    printf("min = %lf\n", min(5, (double) 1.100004, (double) 5, (double) 3.5, (double) 3, (double) 1.1));
}
