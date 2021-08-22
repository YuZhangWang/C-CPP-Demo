#include <stdio.h>
#include <stdlib.h>

//查询某一学生的平均成绩，并写入表格中
int OneGradeAverage(char buff[5005][100]) {
    int num = 0;
    while (1) {
        printf("%s\n", "请输入正确的需要查询平均成绩的学生学号(1-100):");
        scanf("%d", &num);
        if (num >= 0 && num <= 100) {
            break;
        }
    }

    //提取生成数据中所有的成绩
    int grade[1000] = {0};
    int n = 0;
    for (int i = 9; i < 5005; i = i + 5) {
        grade[n] = atoi(buff[i]);
        n++;
    }

    //进行某一学生平均成绩的查询
    int sum = 0;
    int tmp = (num - 1) * 10;
    for (int i = num * 10 - 1; i >= (num - 1) * 10; i--, tmp++) {
        sum = sum + grade[tmp];
    }

    printf("学号为%d学生的平均成绩为:%d\n", num, sum / 10);

    //将某一学生的平均成绩传回表格中，并写入表格中
    FILE *pFile = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "r+");
    fseek(pFile, 0L, SEEK_END);
    fprintf(pFile, "学号为%d学生的平均成绩为:%d\n", num, sum / 10);
    fclose(pFile);

    return 0;
}

//查询每一位学生的平均成绩
int AllGradeAverage(char buff[5005][100]) {
    //提取生成数据中所有的成绩
    int grade[1000] = {0};
    int n = 0;
    for (int i = 9; i < 5005; i = i + 5) {
        grade[n] = atoi(buff[i]);
        n++;
    }

    //将每一位学生的平均成绩输出并传回表格中
    FILE *pFile = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "a+");
    printf("所有学生的平均成绩为:\n");
    fprintf(pFile, "所有学生的平均成绩为:\n");
    for (int i = 0; i < 100; i++) {
        int sum = 0;
        for (int j=0; j < 10; j++) {
            sum = sum + grade[i];
        }
        printf("学号为%d的张%d学生的平均成绩为:%d\n", i+1, i+1, sum / 10);
        fprintf(pFile, "学号为%d的张%d学生的平均成绩为:%d\n", i+1, i+1, sum / 10);
    }
    fclose(pFile);
    return 0;
}

int main() {
    //在tmp文件目录下创建一个允许读写地文件StudentData.xlsx
    FILE *pFile = fopen("D:/Code/C&C++/69StudentScoreTest/tmp/StudentData.xlsx", "w+");
    fputs("班级\t", pFile);
    fputs("姓名\t", pFile);
    fputs("学号\t", pFile);
    fputs("课程\t", pFile);
    fputs("成绩\n", pFile);

    //生成计嵌一班的数据
    for (int i = 0; i < 50; i++) {
        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "C++课程设计");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "离散数学");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "面向对象C++程序设计");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "大学英语2");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "高等数学2");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "体育2");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "职业发展与就业创业指导1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "互联网金融");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "计算机电子电路基础");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌一班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%d\t", i + 1);
        fprintf(pFile, "%s\t", "数据结构");
        fprintf(pFile, "%d\n", rand() % 101);
    }

    //生成计嵌二班的数据
    for (int i = 0; i < 50; i++) {
        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "C语言程序设计");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "计算机专业导论");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "中国近现代史纲要");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "大学英语1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "思想道德修养与法律基础");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "高等数学1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "体育1");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "军事训练");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "军事理论");
        fprintf(pFile, "%d\n", rand() % 101);

        fputs("计嵌二班\t", pFile);
        fprintf(pFile, "%s", "张");
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%d\t", i + 51);
        fprintf(pFile, "%s\t", "心理健康教育与服务");
        fprintf(pFile, "%d\n", rand() % 101);
    }

    //保存并关闭文件
    fclose(pFile);

    //读取生成的文件，并输出
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

    //查询某一学生的平均成绩
    OneGradeAverage(buff);
    //查询每一个学生的平均成绩
    AllGradeAverage(buff);
    //关闭并保存文件
    fclose(pFile);

    return 0;
}