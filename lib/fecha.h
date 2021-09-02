#include <stdio.h>
#include <time.h>

int fecha() {

        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        printf("%s",output);

        return 0;
}