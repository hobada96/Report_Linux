#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int menu_display(void);
int dbcreate(int argc, char *argv[]);
int dqupdate(int argc, char *argv[]);
int dbquery(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	int fd,select;
	if(argc < 2){
		fprintf(stderr, "사용법 : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}

	while((select = menu_display())!= 0)
	{
		if(select == 1) dbcreate(argc,argv);
		else if (select == 2) dbquery(argc,argv);
		else if (select == 3) dqupdate(argc,argv);
		else printf("잘못된 입력입니다. 재입력 해주세요");
	}
}


int menu_display(){
	int select = 0;
	printf("1.db 생성");
	printf("2.db 질의");
	printf("3.db 갱신");
	printf("0. 종료");
	scanf("%d",&select);
	return select;
}

int dbcreate(int argc, char *argv[]){
	int fd;
	struct student rec;

	if(argc < 2){
		fprintf(stderr, "사용법 : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	
	printf("%9s %-8s %-4s","학번","이름","점수");
	while(scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3){
		lseek(fd,(rec.id - START_ID) * sizeof(rec), SEEK_SET);
		write(fd,&rec,sizeof(rec));	
	}
	close(fd);
	exit(0);
}

int dqupdate(int argc, char *argv[])
{
    	int fd, id;
	char c;
	struct student rec;

	if(argc < 2){
		fprintf(stderr, "사용법 : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}

	do{
		printf("\n수정할 학생의 학번을 입력:");
		if(scanf("%d", &id) == 1){
			lseek(fd,(id-START_ID)*sizeof(rec),SEEK_SET);
			if((read(fd,&rec,sizeof(rec))>0) && (rec.id!= 0))
			{
				printf("학번:%d\t이름:%s\t점수:%d\n",rec.id,rec.name,rec.score);
				printf("새로운 점수: ");
				scanf("%d",&rec.score);
				lseek(fd,(long)-sizeof(rec),SEEK_CUR);
				write(fd,&rec,sizeof(rec));
			}
			else printf("레코드 %d 없음\n",id);
		}
		else printf("입력오류\n");
		printf("계속하시겠습니까?(Y/N)");
		scanf("%c",&c);
	} while(c == 'Y');
	close(fd);
	exit(0);
}

int dbquery(int argc, char *argv[])
{
    	int fd,id;
	char c;
	struct student rec;

	if(argc < 2){
		fprintf(stderr, "사용법 : %s file\n",argv[0]);
		exit(1);
	}

	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	
	do{
		printf("\n검색할 학생의 학번을 입력:");
		if(scanf("%d", &id) == 1){
			lseek(fd,(id-START_ID)*sizeof(rec),SEEK_SET);
			if((read(fd,&rec,sizeof(rec))>0) && (rec.id!= 0))
				printf("학번:%d\t이름:%s\t점수:%d\n",rec.id,rec.name,rec.score);
			else printf("레코드 %d 없음\n",id);
		}
		else printf("입력오류");
		printf("계속하시겠습니까?(Y/N)");
		scanf("%c",&c);
	} while(c == 'Y');
	close(fd);
	exit(0);
}
