#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int Wsize ()
{

     struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    // printf ("lines %d\n", w.ws_row);
    // printf ("columns %d\n", w.ws_col);

    for (int i = 0; i < w.ws_col; i++)
    {
        printf("=");
    }
        

    return 0;  // make sure your main returns int
}
