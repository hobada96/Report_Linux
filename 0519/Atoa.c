#include <stdio.h>

int main(){
	char a,b;
	
	printf("�빮�� �Է� : ");
	scanf("%c",&a);
	fflush(stdin);
	printf("�ҹ��� �Է� : ");
	scanf("%c,",&b);
	printf("�Է��� %c�� �ҹ��ڴ� %c �Դϴ�.\n",a,a+32);
	printf("�Է��� %c�� �빮�ڴ� %c �Դϴ�.",b,b-32);
	
	return 0;
}
