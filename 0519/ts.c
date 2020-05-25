#include <stdio.h>

int main(){
	char a,b;
	
	printf("대문자 입력 : ");
	scanf("%c",&a);
	getchar();
	printf("소문자 입력 : ");
	scanf("%c,",&b);
	printf("%c",b);
	printf("입력한 %c의 소문자는 %c 입니다.\n",a,a+32);
	printf("입력한 %c의 대문자는 %c 입니다.",b,b-32);
	
	return 0;
}
