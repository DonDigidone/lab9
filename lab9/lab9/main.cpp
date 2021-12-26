#include "Header.h"



int main()
{
    setlocale(LC_ALL, "ru");

    cout << "�������� �������� � ��������:" << endl;
    cout << " ����� �� ���������" << endl;
    cout << " 1)�������� ������� � �����" << endl;
    cout << " 2)������� � ������� �������� �������" << endl;
    cout << " 3)������� �������� �������" << endl;
    cout << " 4)������� ����� �������" << endl;
   
    Queue queue;
    int opt;
    cin >> opt;

    while (opt != 0)
    {
        switch (opt)
        {
        case 1:
        {
            int a;
            cout << "������� ����� ��� �������: ";
            cin >> a;
            queue.push(a);
            break;
        }
        case 2:
        {
            cout << "�������� ���������� ��������� ��������: " << queue.pop() << endl;
            break;
        }
        case 3:
        {
            cout << "�������� ��������� ��������: " << queue.peek() << endl;
            break;
        }

        case 4:
            cout << "����� �������: " << queue.get_size() << endl;
            break;
       
        default:
            cout << "������� ������������ ��������" << endl;
        }
        cin >> opt;
    }
    return 0;
}