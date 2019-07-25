#include <stdio.h>
#include <stdlib.h>
#include "rs232.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define buffersize 4096

int main()
{
    printf("Serial Communication in C\n");
    int i, n,
        cport_nr=5,        /* /dev/ttyS0 (COM1 on windows) */
        bdrate=9600;       /* 9600 baud */

    unsigned char buf[buffersize];

    char mode[]= {'8','N','1', 0};


    if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
    {
        printf("Can not open comport\n");

        return(0);
    }
    printf("c to continue, other to quit\n");
    while(getc(stdin) == 'c')
    {
        fflush(stdin);

        if(RS232_SendByte(cport_nr, '1')){
            printf("error sending byte");
            return 0;
        }

        n = RS232_PollComport(cport_nr, buf, buffersize);

        if(n > 0)
        {
            buf[n] = 0;   /* always put a "null" at the end of a string! */

            for(i=0; i < n; i++)
            {
                if(buf[i] < 32)  /* replace unreadable control-codes by dots */
                {
                    buf[i] = '.';
                }
            }

            printf("received %i bytes: %s\n", n, (char *)buf);
        }

#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);  /* sleep for 100 milliSeconds */
#endif
    }

    return(0);
    return 0;
}
