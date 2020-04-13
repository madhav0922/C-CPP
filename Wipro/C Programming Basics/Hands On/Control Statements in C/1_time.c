#include<stdio.h>
int main()
    {
        unsigned int sec_time,hrs,mins,secs;
        printf("Enter the time in seconds: ");
        scanf("%d",&sec_time);
        secs = sec_time%60;
        mins = (sec_time/60)%60;
        hrs = sec_time/3600;
        printf("Time is %d hrs %d mins %d secs\n",hrs,mins,secs);
        return 0;
    }