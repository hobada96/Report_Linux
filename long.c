#include<stdio.h>
#include<string.h>
#define MAXLINE 100

void copy(char from[], char to[]);
char *mygets(char *buf, size_t size);
char line[MAXLINE];
char longest[MAXLINE];

int main(){
	int len;
	int max;
	max = 0;
	while(mygets(line,sizeof(line)) != NULL){
		len = strlen(line);
		if(len > max){
			max = len;
			copy(line,longest);
		}
	}

	if (max > 0)
		printf("%s",longest);
		return 0;
}

void copy(char from[], char to[]){
	int i;
	i = 0;
	while((to[i] = from[i] != '\0')
		++i;
}

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
