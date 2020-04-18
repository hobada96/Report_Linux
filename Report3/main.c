#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "./student.h"

int menu_display(void);
int sub_menu_display01(void);
int sub_menu_display02(void);
void sub_main01(void);
void press_any_key(void);

int main(void)
{
	int select = 0;
	while(menu_display()!= 0)
	{
		if(select == 1)
		else if (select == 2)
		else if (select == 3)
		else printf("잘못된 입력입니다. 재입력 해주세요");
	}
}


int menu_display(){
	printf("1.db 생성");
	printf("2.db 질의");
	printf("3.db 갱신");
	printf("0. 종료");
}


