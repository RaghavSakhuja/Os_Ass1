#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#define p(a) printf("%s\n",a)
#define plen(a) printf("%ld\n",strlen(a));

int main(int argc, char const *argv[])
{
