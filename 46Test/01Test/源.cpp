#include<iostream>
using namespace std;

class Array//������
{
private:
    int array[10] = {0};

public:
    void Setvalue(); //������Ԫ������ֵ
    void ShowValue();//�������Ԫ�ص�ֵ����Ļ
    int GetMax();//�ҳ������е����Ԫ��
};

void Array::Setvalue()
{
    cout << "������10������:"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i] ;
    }
}

void Array::ShowValue()
{
    cout << "����Ԫ��Ϊ:"<< endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int Array::GetMax()
{
    int max = array[0];

    for (int i = 0; i < 10; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    Array arr;
    int max;

    arr.Setvalue();
    arr.ShowValue();
    max = arr.GetMax();

    cout << "��������ֵΪ:" << max << endl;

    return 0;
}