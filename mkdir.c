#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#define p(a) printf("%s\n",a)

int main(int argc, char const *argv[])
{
	int flag1=(!strcmp(argv[1],"x")); //-v
	int flag2=(!strcmp(argv[2],"x")); //-i
    // printf("%d %d\n",flag1,flag2);
    return 0;

}