#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#define p(a) printf("%s\n",a)



int main(int argc,char* argv[]){
	// p("aaaaaaaaaaa");
	struct dirent* d;
	DIR *dh =opendir(argv[0]);
	int flag1=(!strcmp(argv[1],"x")); //-a
	int flag2=(!strcmp(argv[2],"x")); //-1
	// printf("%d %d\n",flag1,flag2);
	if(!dh){
	
		if (errno = ENOENT)
		{
			//If the directory is not found
			p("Directory doesn't exist");
		}
		else
		{
			//If the directory is not readable then throw error and exit
			p("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while((d=readdir(dh))!=NULL){

		char check='.';
		char t=d->d_name[0];
		if(flag1==0){
			if(t==check){
				continue;
			}
		}
		printf("%s ",d->d_name);
		if(flag2==1){
			printf("\n");
		}
	}
	if(flag2==0) printf("\n");
	closedir(dh);
}