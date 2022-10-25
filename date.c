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
    
    char* format=argv[1];
    time_t t=time(NULL);
    struct tm curtime=*localtime(&t);
    // p(format);
    if(format[0]=='+'){
        if(flag1){
            p("Multiple formats specified");
        }
        else if(flag2){
            struct tm utc=*gmtime(&t);
            char* days[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
            char* months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
            for(int i=0;i<strlen(format);i++){
                int a=format[i];
                int b='%';
                int c=strlen(format);

                if((a==b) && (i!=(c-1))){
                    if(format[i+1]=='b'){
                        printf("%s",months[utc.tm_mon]);
                        i++;
                    }
                    else if(format[i+1]=='a'){
                        printf("%s",days[utc.tm_wday]);
                        i++;                        
                    }
                    else if(format[i+1]=='m'){
                        printf("%d",utc.tm_mon+1);
                        i++;

                    }
                    else if(format[i+1]=='Y'){
                        printf("%d",utc.tm_year+1900);
                        i++;

                    }
                    else if(format[i+1]=='d'){
                        printf("%d",utc.tm_mday);
                        i++;
                    }
                    else if(format[i+1]=='H'){
                        printf("%d",utc.tm_hour);
                        i++;
                    }
                    else if(format[i+1]=='M'){
                        printf("%d",utc.tm_min);
                        i++;

                    }
                    else if(format[i+1]=='S'){
                        printf("%d",utc.tm_sec);
                        i++;
                    }
                    else{
                          printf("%s",format[i]);
                          printf("%s",format[i+1]);
                          i++;
                    }
                }

                else{
                    printf("%c",format[i]);
                }
            }

        }
        else{      
            char* days[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
            char* months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
            struct tm utc=curtime;
            for(int i=0;i<strlen(format);i++){
                // p("cfsjnala"); 
                // printf("%c",format[i]);   
                // p("none");  
                int a=format[i];
                int b='%';
                int c=strlen(format);
                // printf("%d %d %d\n",a,b,c);
                if(a==b){
                    // p("fuck");
                }
                // p("vhi");
                if((a==b) && (i!=(c-1))){
                    // p("aaaaaaaaaaa");
                    if(format[i+1]=='b'){
                        printf("%s",months[utc.tm_mon]);
                    }
                    else if(format[i+1]=='a'){
                        printf("%s",days[utc.tm_wday]);
                    }
                    else if(format[i+1]=='m'){
                        printf("%d",utc.tm_mon+1);

                    }
                    else if(format[i+1]=='Y'){
                        printf("%d",utc.tm_year+1900);

                    }
                    else if(format[i+1]=='d'){
                        printf("%d",utc.tm_mday);
                    }
                    else if(format[i+1]=='H'){
                        printf("%d",utc.tm_hour);
                    }
                    else if(format[i+1]=='M'){
                        printf("%d",utc.tm_min);

                    }
                    else if(format[i+1]=='S'){
                        printf("%d",utc.tm_sec);
                    }
                    else{
                        printf("%s",format[i]);
                        printf("%s",format[i]);

                    }
                    i++;
                }
                else{
                    printf("%c",format[i]);
                    // p("babc");
                }
            }
        }
    }
    else if(!strcmp(format,"none")){
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
    }
    else{
        p("Invalid date format");
    }
    return 0;  
}