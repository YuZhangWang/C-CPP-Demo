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
    cout << "Clock�û��㷨" << endl;
    if (pageCount <= blockCount) {
        cout << "ȱҳ����Ϊ" << 0 << endl;
        cout << "ȱҳ��Ϊ" << 0 << endl;
    }
    else {
        int noPage = 0;
        int i, j;
        int *bc1 = new int[blockCount];
        for (i = 0; i < blockCount; i++)           //����λ��ʼ��
        {
            bc1[i] = 0;
        }
        int replace = 0;
        for (i = 0; i < pageCount; i++) {
            cout << "����ҳ��" << pc[i] << endl;
            int index = Travel(bc, blockCount, pc[i]);
            if (index == -1)              //ҳ�治���ڴ�
            {
                for (j = 0; j < blockCount; j++)     //���ҷ���λΪ0��ҳ��
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
                cout << "����������";
                Print(bc, blockCount);
                cout << "��־λ�����";
                Print(bc1, blockCount);
            }
            else {
                bc1[index] = 1;
                replace = (index + 1) % blockCount;
                cout << "����������";
                Print(bc, blockCount);
                cout << "��־λ�����";
                Print(bc1, blockCount);
            }
            cout << endl;
        }
        cout << "ȱҳ����Ϊ:" << noPage << endl;
        cout << "ȱҳ��Ϊ:" << (float) noPage / pageCount << endl;
        delete bc1;
    }
}

int main() {
    int pageCount, blockCount, i;
    cout << "����ҳ����" << endl;
    cin >> pageCount;
    int *pc = new int[pageCount];
    cout << "����ҳ������" << endl;
    for (i = 0; i < pageCount; i++) {
        cin >> pc[i];
    }
    cout << "�����������" << endl;
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