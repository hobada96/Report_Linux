#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* �й��� �Է¹޾� �ش� �л��� ���ڵ带 ���Ͽ��� �о� ����Ѵ�. */
int main(int argc, char *argv[])
{
    int fd, id;
    char c;
    struct student rec;

   if (argc < 2) {
        fprintf(stderr,  "���� : %s file\n", argv[0]);
        exit(1);
   }

   if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("\n�˻��� �л��� �й� �Է�:");
        if (scanf("%d", &id) == 1) {
            lseek(fd, (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) 
                printf("�й�:%d\t �̸�:%s\t ����:%d\n", 
                        rec.id, rec.name, rec.score);
            else printf("���ڵ� %d ����\n", id);
        }
        else printf("�Է� ����"); 

        printf("����ϰڽ��ϱ�?(Y/N)");
        scanf(" %c", &c);
    } while (c == 'Y');
   
    close(fd);
    exit(0);
}
