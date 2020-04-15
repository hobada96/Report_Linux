#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* �й��� �Է¹޾� �ش� �л� ���ڵ带 �����Ѵ�. */
int main(int argc, char *argv[])
{
    int fd, id;
    char c;
    struct student rec;

    if (argc < 2) {
        fprintf(stderr,  "���� : %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("������ �л��� �й� �Է�: ");
        if (scanf("%d", &id) == 1) {
            lseek(fd,  (long) (id-START_ID)*sizeof(rec), SEEK_SET);
            if ((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) {
                printf("�й�:%8d\t �̸�:%4s\t ����:%4d\n", 
                       rec.id, rec.name, rec.score);
           printf("���ο� ����: ");
           scanf("%d", &rec.score);
                lseek(fd, (long) -sizeof(rec), SEEK_CUR);
                write(fd, &rec, sizeof(rec));
            }
            else printf("���ڵ� %d ����\n", id);
        }
        else printf("�Է¿���\n");
        printf("����ϰڽ��ϱ�?(Y/N)");
        scanf(" %c",&c);
    } while (c == 'Y');

    close(fd);
    exit(0);
}

