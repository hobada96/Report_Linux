#include<stdio.h>
#include<string.h>
#define MAXLINE 100

char *mygets(char *buf, size_t size){
	if (buf != NULL && size > 0){
		if(fgets(buf,size,stdin)){
			buf[strcspn(buf,"\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
}
