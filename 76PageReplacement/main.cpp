#include<iostream>

using namespace std;

void Print(int bc[], int blockCount) {
    for (int i = 0; i < blockCount; i++) {
        cout << bc[i] << " ";
    }
    cout << endl;
}

int Travel(int bc[], int blockCount, int x) {
    int index = -1;
    int i;
    for (i = 0; i < blockCount; i++) {
        if (bc[i] == x) {
            index = i;
            break;
        }
    }
    return index;
}

void NRU(int pc[], int bc[], int pageCount, int blockCount) {
    cout << "Clock置换算法" << endl;
    if (pageCount <= blockCount) {
        cout << "缺页次数为" << 0 << endl;
        cout << "缺页率为" << 0 << endl;
    }
    else {
        int noPage = 0;
        int i, j;
        int *bc1 = new int[blockCount];
        for (i = 0; i < blockCount; i++)           //访问位初始化
        {
            bc1[i] = 0;
        }
        int replace = 0;
        for (i = 0; i < pageCount; i++) {
            cout << "引用页：" << pc[i] << endl;
            int index = Travel(bc, blockCount, pc[i]);
            if (index == -1)              //页面不在内存
            {
                for (j = 0; j < blockCount; j++)     //查找访问位为0的页面
                {
                    if (bc1[replace] == 1) {
                        bc1[replace] = 0;
                        replace = (replace + 1) % blockCount;
                    }
                    else {
                        break;
                    }
                }
                bc[replace] = pc[i];
                bc1[replace] = 1;
                replace = (replace + 1) % blockCount;
                noPage++;
                cout << "物理块情况：";
                Print(bc, blockCount);
                cout << "标志位情况：";
                Print(bc1, blockCount);
            }
            else {
                bc1[index] = 1;
                replace = (index + 1) % blockCount;
                cout << "物理块情况：";
                Print(bc, blockCount);
                cout << "标志位情况：";
                Print(bc1, blockCount);
            }
            cout << endl;
        }
        cout << "缺页次数为:" << noPage << endl;
        cout << "缺页率为:" << (float) noPage / pageCount << endl;
        delete bc1;
    }
}

int main() {
    int pageCount, blockCount, i;
    cout << "输入页面数" << endl;
    cin >> pageCount;
    int *pc = new int[pageCount];
    cout << "输入页面走向" << endl;
    for (i = 0; i < pageCount; i++) {
        cin >> pc[i];
    }
    cout << "输入物理块数" << endl;
    cin >> blockCount;

    int *bc = new int[blockCount];

    for (i = 0; i < blockCount; i++) {
        bc[i] = -1;
    }
    NRU(pc, bc, pageCount, blockCount);

    delete bc;
    delete pc;
    return 0;
}