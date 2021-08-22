#include<iostream>
using namespace std;

class Array//声明类
{
private:
    int array[10] = {0};

public:
    void Setvalue(); //对数组元素设置值
    void ShowValue();//输出数组元素的值到屏幕
    int GetMax();//找出数组中的最大元素
};

void Array::Setvalue()
{
    cout << "请输入10个整数:"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i] ;
    }
}

void Array::ShowValue()
{
    cout << "数组元素为:"<< endl;
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

    cout << "数组的最大值为:" << max << endl;

    return 0;
}