#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

void ls_Inode(struct stat buf)
{
        printf("%d      ", (unsigned int)buf.st_ino);
}

void ls_Mode(struct stat buf)
{
        printf("%lo      ", (unsigned long)buf.st_mode);
}

void ls_FSize(struct stat buf)
{
        printf("%ld      ", buf.st_size);
}

void ls_option(struct stat buf, char * option)
{
        if(strcmp(option, "-l") == 0)
        {
                ls_Mode(buf);
                ls_Inode(buf);
                ls_FSize(buf);
        }

        else if(strcmp(option, "-i") == 0)
        {
                ls_Inode(buf);
        }
}

int main(int argc, char *argv[])
{
        char * cwd = (char *)malloc(sizeof(char) * 1024);
        memset(cwd, 0, 1024);  //메모리의 시작 지점부터 연속된 범위의 값을 어떤값으로 지정, void *memset(void *ptr,int value, size_t num);

        DIR * dir = NULL;
        struct dirent * entry;
        struct stat buf;
        getcwd(cwd, 1024); //작업 디렉토리의 이름을 얻어온다.

        if( (dir = opendir(cwd)) == NULL)
        {
                printf("opendir() error\n");
                exit(1);
        }

        while( (entry = readdir(dir)) != NULL)
        {
                lstat(entry->d_name, &buf);  // File정보를 알아옴.
                if(S_ISREG(buf.st_mode))        //File
                        printf("FILE    ");
                else if(S_ISDIR(buf.st_mode))  	//Dir
                        printf("DIR     ");
                else				//Else
                        printf("Error");
                if(argc > 1)
                        ls_option(buf, argv[1]);
                printf("%s      \n", entry->d_name);
        }
        free(cwd);
        closedir(dir);

        return 0;

}

//https://go-it.tistory.com/4 코드를 들고왔으며, 코드에 대한 간략한 설명과 이해 추가.
