#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#define p(a) printf("%s\n",a)

int main(int argc, char const *argv[])
{
	int flag1=(!strcmp(argv[2],"x")); //-v
	int flag2=(!strcmp(argv[3],"x")); //-i
    // printf("%d %d\n",flag1,flag2);
    char* file=argv[1];
    if(flag2){
        printf("rm: remove regular file '%s'? ",file);
        char term[10];
        scanf("%s",term);
        if((!strcmp(term,"y")) || (!strcmp(term,"yes"))){
            if(remove(file)==0){
                if(flag1){
                    printf("removed : %s\n",file);
                }
            }
            else{
                    printf("Could not delete the file : %s\n",file);
            }
        }
    }
    else{
        if(remove(file)==0){
            if(flag1){
                    printf("removed : %s\n",file);
            }
        }
        else{
            printf("Could not delete the file : %s\n",file);
        }
    }
    return 0;
}