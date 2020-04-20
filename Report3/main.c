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
		fprintf(stderr, "���� : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	close(fd);
	
	while((select = menu_display())!= 0)
	{
		if(select == 1) dbcreate(argc,argv);
		else if (select == 2) dbquery(argc,argv);
		else if (select == 3) dqupdate(argc,argv);
		else printf("�߸��� �Է��Դϴ�. ���Է� ���ּ���");
	}
}


int menu_display(){
	int select = 0;
	printf("1.db ����");
	printf("2.db ����");
	printf("3.db ����");
	printf("0. ����");
	scanf("%d",&select);
	return select;
}

int dbcreate(int argc, char *argv[]){
	struct student rec;
	int fd;
	
	if(argc < 2){
		fprintf(stderr, "���� : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	
	printf("%9s %-8s %-4s","�й�","�̸�","����");
	while(scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3){
		lseek(fd,(rec.id - START_ID) * sizeof(rec), SEEK_SET);
		write(fd,&rec,sizeof(rec));
		break;
	}
	close(fd);
	return 0;
}

int dqupdate(int argc, char *argv[])
{
    int fd, id;
	char c = 0;
	struct student rec;

	if(argc < 2){
		fprintf(stderr, "���� : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	
	do{
		printf("\n������ �л��� �й��� �Է�:");
		if(scanf("%d", &id) == 1){
			lseek(fd,(id-START_ID)*sizeof(rec),SEEK_SET);
			if((read(fd,&rec,sizeof(rec))>0) && (rec.id!= 0))
			{
				printf("�й�:%d\t�̸�:%s\t����:%d\n",rec.id,rec.name,rec.score);
				printf("���ο� ����: ");
				scanf("%d",&rec.score);
				lseek(fd,(long)-sizeof(rec),SEEK_CUR);
				write(fd,&rec,sizeof(rec));
			}
			else printf("���ڵ� %d ����\n",id);
		}
		else printf("�Է¿���\n");
		printf("����Ͻðڽ��ϱ�?(Y/N)");
		fflush(stdin); 
		scanf("%c",&c);
	} while(c == 'Y');
	
	close(fd);
	return 0;
}

int dbquery(int argc, char *argv[])
{
    int fd,id;
	char c = 0;
	struct student rec;

	if(argc < 2){
		fprintf(stderr, "���� : %s file\n",argv[0]);
		exit(1);
	}
	
	if((fd = open(argv[1],O_WRONLY|O_CREAT,0640)) == -1){
		perror(argv[1]);
		exit(2);
	}
	
	do{
		printf("\n�˻��� �л��� �й��� �Է�:");
		if(scanf("%d", &id) == 1){
			lseek(fd,(id-START_ID)*sizeof(rec),SEEK_SET);
			if((read(fd,&rec,sizeof(rec))>0) && (rec.id!= 0))
				printf("�й�:%d\t�̸�:%s\t����:%d\n",rec.id,rec.name,rec.score);
			else printf("���ڵ� %d ����\n",id);
		}
		else printf("�Է¿���");
		fflush(stdin);
		printf("����Ͻðڽ��ϱ�?(Y/N)");
		scanf("%c",&c);
	} while(c == 'Y');
	close(fd);
	return 0;
}

