#include <stdio.h>
#include <stdlib.h>

//��ѯĳһѧ����ƽ���ɼ�����д������
int OneGradeAverage(char buff[5005][100]) {
    int num = 0;
    while (1) {
        printf("%s\n", "��������ȷ����Ҫ��ѯƽ���ɼ���ѧ��ѧ��(1-100):");
        scanf("%d", &num);
        if (num >= 0 && num <= 100) {
            break;
        }
    }

    //��ȡ�������������еĳɼ�
    int grade[1000] = {0};
    int n = 0;
    for (int i = 9; i < 5005; i = i + 5) {
        grade[n] = atoi(buff[i]);
        n++;
    }

    //����ĳһѧ��ƽ���ɼ��Ĳ�ѯ
    int sum = 0;
    int tmp = (num - 1) * 10;
    for (int i = num * 10 - 1; i >= (num - 1) * 10; i--, tmp++) {
        sum = sum + grade[tmp];
    }

    printf("ѧ��Ϊ%dѧ����ƽ���ɼ�Ϊ:%d\n", num, sum / 10);

    //��ĳһѧ����ƽ���ɼ����ر���У���д������
    FILE *pFile = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "r+");
    fseek(pFile, 0L, SEEK_END);
    fprintf(pFile, "ѧ��Ϊ%dѧ����ƽ���ɼ�Ϊ:%d\n", num, sum / 10);
    fclose(pFile);

    return 0;
}

//��ѯÿһλѧ����ƽ���ɼ�
int AllGradeAverage(char buff[5005][100]) {
    //��ȡ�������������еĳɼ�
    int grade[1000] = {0};
    int n = 0;
    for (int i = 9; i < 5005; i = i + 5) {
        grade[n] = atoi(buff[i]);
        n++;
    }

    //��ÿһλѧ����ƽ���ɼ���������ر����
    FILE *pFile = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "a+");
    printf("����ѧ����ƽ���ɼ�Ϊ:\n");
    fprintf(pFile, "����ѧ����ƽ���ɼ�Ϊ:\n");
    for (int i = 0; i < 100; i++) {
        int sum = 0;
        for (int j=0; j < 10; j++) {
            sum = sum + grade[i];
        }
        printf("ѧ��Ϊ%d����%dѧ����ƽ���ɼ�Ϊ:%d\n", i+1, i+1, sum / 10);
        fprintf(pFile, "ѧ��Ϊ%d����%dѧ����ƽ���ɼ�Ϊ:%d\n", i+1, i+1, sum / 10);
    }
    fclose(pFile);
    return 0;
}

int main() {
    //��tmp�ļ�Ŀ¼�´���һ�������д���ļ�StudentData.xlsx
    FILE *pFile = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "w+");
    fputs("�༶\t", pFile);
    fputs("����\t", pFile);
    fputs("ѧ��\t", pFile);
    fputs("�γ�\t", pFile);
    fputs("�ɼ�\n", pFile);

    //���ɼ�Ƕһ�������
    for (int i = 0; i < 50; i++) {
        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "C++�γ����");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "��ɢ��ѧ");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "�������C++�������");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "��ѧӢ��2");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "�ߵ���ѧ2");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "����2");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "ְҵ��չ���ҵ��ҵָ��1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "����������");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "��������ӵ�·����");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕһ��\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "���ݽṹ");
        fprintf(pFile, "%d\n", rand() % 101);
    }

    //���ɼ�Ƕ���������
    for (int i = 0; i < 50; i++) {
        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "C���Գ������");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "�����רҵ����");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "�й����ִ�ʷ��Ҫ");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "��ѧӢ��1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "˼����������뷨�ɻ���");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "�ߵ���ѧ1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "����1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "����ѵ��");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "��������");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("��Ƕ����\t", pFile);
        fprintf(pFile, "%s", "��");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "���������������");
        fprintf(pFile, "%d\n", rand() % 101);
    }

    //���沢�ر��ļ�
    fclose(pFile);

    //��ȡ���ɵ��ļ��������
    FILE *pf = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "r+");
    char buff[5005][100] = {};
    int flag = 0;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(pf, "%s", buff[flag]);
            printf("%-25s", buff[flag]);
            flag++;
        }
        printf("\n");
    }

    //��ѯĳһѧ����ƽ���ɼ�
    OneGradeAverage(buff);
    //��ѯÿһ��ѧ����ƽ���ɼ�
    AllGradeAverage(buff);
    //�رղ������ļ�
    fclose(pFile);

    return 0;
}