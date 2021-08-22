#include"stdio.h"
#include"stdlib.h"
#include"iostream.h"

#define maxsize 100

//先来先服务调度算法
void FCFS(int array[], int m) {
    int sum = 0, j, i, now;
    cout << "请输入当前的磁道号：";
    cin >> now;
    for (i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    sum += abs(now - array[0]);
    for (i = 0, j = 1; j < m; i++, j++) {
        sum += abs(array[j] - array[i]);
    }
    cout << "移动的总道数： " << sum << endl;
}

//最短寻道时间优先调度算法
void ShortPath(int array[], int m) {
    int temp;
    int k = 1;
    int now, l, r;
    int i, j, sum = 0;
    for (i = 0; i < m; i++)
        for (j = i + 1; j < m; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    for (i = 0; i < m; i++) {
        cout << array[i] << " ";
    }/*排序*/
    cout << "请输入当前的磁道号：";
    cin >> now;
    if (array[m - 1] <= now) {
        for (i = m - 1; i >= 0; i--)
            cout << array[i] << " ";
        sum = now - array[0];
    }
    else if (array[0] >= now) {
        for (i = 0; i < m; i++)
            cout << array[i] << " ";
        sum = array[m - 1] - now;
    }
    else {
        while (array[k] < now) {
            k++;
        }
        l = k - 1;
        r = k;
        /*确定当前磁道在已排的序列中的位置，后面的算法都用到了，可以直接复杂后少量修改，节省时间。*/
        while ((l >= 0) && (r < m)) {
            if ((now - array[l]) <= (array[r] - now)) {
                cout << array[l] << " ";
                sum += now - array[l];
                now = array[l];
                l = l - 1;
            }
            else {
                cout << array[r] << " ";
                sum += array[r] - now;
                now = array[r];
                r = r + 1;
            }
        }
        if (l = -1) {
            for (j = r; j < m; j++) {
                cout << array[j] << " ";
            }
            sum += array[m - 1] - array[0];
        }
        else {
            for (j = l; j >= 0; j--) {
                cout << array[j] << " ";
            }
            sum += array[m - 1] - array[0];
        }
    }
    cout << "移动的总道数： " << sum << endl;
}

//电梯调度算法
void Elevator(int array[], int m) //先</A>要给出当前磁道号和移动臂的移动方向
{
    int temp;
    int k = 1;
    int now, l, r, d;
    int i, j, sum = 0;
    for (i = 0; i < m; i++)
        for (j = i + 1; j < m; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    for (i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << "请输入当前的磁道号：";
    cin >> now;
    if (array[m - 1] <= now) {
        for (i = m - 1; i >= 0; i--)
            cout << array[i] << " ";
        sum = now - array[0];
    }
    else if (array[0] >= now) {
        for (i = 0; i < m; i++)
            cout << array[i] << " ";
        sum = array[m - 1] - now;
    }
    else {
        while (array[k] < now) {
            k++;
        }
        l = k - 1;
        r = k;
        cout << "请输入当前移动臂的移动的方向 (1 表示向内 ，0表示向外) : ";
        cin >> d;
        if (d == 0) {
            for (j = l; j >= 0; j--) {
                cout << array[j] << " ";
            }
            for (j = r; j < m; j++) {
                cout << array[j] << " ";
            }
            sum = now - 2 * array[0] + array[m - 1];
        }
        else {
            for (j = r; j < m; j++) {
                cout << array[j] << " ";
            }
            for (j = l; j >= 0; j--) {
                cout << array[j] << " ";
            }

            sum = -now - array[0] + 2 * array[m - 1];
        }
    }
    cout << "移动的总道数： " << sum << endl;
}

void main() {
    int c;
    FILE *fp;
    int cidao[maxsize];
    int i = 0, count;
    fp = fopen("cidao.txt", "r+");
    if (fp == NULL) {
        cout << "文件打不开!" << endl;
        exit(0);
    }
    while (!feof(fp)) {
        fscanf(fp, "%d", &cidao[i]);
        i++;
    }
    count = i;

    for (i = 0; i < count; i++) {
        printf("%5d", cidao[i]);
    }
    cout << endl;
    while (1) {
        cout << endl << "系统的菜单如下：" << endl;
        printf("1. 先来先服务     2. 最短寻道时间优先     3. 电梯调度");
        cout << endl;
        printf("4. 退出");
        cout << endl;
        cout << "请选择：";
        cin >> c;
        if (c > 3)
            break;
        switch (c) {
            case 1:
                FCFS(cidao, count);
                break;
            case 2:
                ShortPath(cidao, count);
                break;
            case 3:
                Elevator(cidao, count);
                break;
        }
    }
}