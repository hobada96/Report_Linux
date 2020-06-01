#include <stdio.h>

static void exit_handler1(void), exit_handler2(void);
int main(void) {
	if (atexit(exit_handler1) != 0)
 		perror("exit_handler1 ����� �� ����");
 	if (atexit(exit_handler2) != 0)
		perror("exit_handler2 ����� �� ����");
	printf("main �� \n");
 
 	exit(0);
 }


 static void exit_handler1(void) {
 printf("ù ��° exit ó����\n");
 }

 static void exit_handler2(void) {
 printf("�� ��° exit ó����\n");
 }
