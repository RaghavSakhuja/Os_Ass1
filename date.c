#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <time.h>
#define p(a) printf("%s\n",a)
#define plen(a) printf("%ld\n",strlen(a));

int main(int argc, char const *argv[])
{
    int flag1=(!strcmp(argv[2],"x")); //-I
	int flag2=(!strcmp(argv[3],"x")); //-u` 
    
    time_t t=time(NULL);
    struct tm curtime=*localtime(&t);
    if(flag1){

        printf("%d-%d-%d\n",curtime.tm_year+1900,curtime.tm_mon+1,curtime.tm_mday);
    }
    else if(flag2){
        struct tm utc=*gmtime(&t);
        char* days[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        char* months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        printf("%s %s %d %d:%d:%d UTC %d\n",days[utc.tm_wday],months[utc.tm_mon],utc.tm_mday,utc.tm_hour,utc.tm_min,utc.tm_sec,utc.tm_year+1900);
    }
    else{
        printf("%s",ctime(&t));
    }
    
    return 0;  
}