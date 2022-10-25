#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#define p(a) printf("%s\n",a)

int main(int argc, char const *argv[])
{
	int flag1=(!strcmp(argv[2],"x")); //-p
	int flag2=(!strcmp(argv[3],"x")); //-v
    char* file=argv[1];
    // printf("%d %d\n",flag1,flag2);
    if(flag1){
            if(mkdir(file)==0){
                if(flag2){
                    printf("created : %s\n",file);
                }
            }
            else{
                    printf("Could not create the file : %s\n",file);
            }
    }
    else{
        if(mkdir(file)==0){
            if(flag2){
                    printf("created : %s\n",file);
            }
        }
        else{
            printf("Could not create the file : %s\n",file);
        }
    }

    return 0;

}