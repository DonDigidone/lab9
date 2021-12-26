#include "Header.h"



int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Выберите действие с очередью:" << endl;
    cout << " Выйти из программы" << endl;
    cout << " 1)Вставить элемент в конец" << endl;
    cout << " 2)Удалить и вывести головной элемент" << endl;
    cout << " 3)Вывести головной элемент" << endl;
    cout << " 4)Вывести длину очереди" << endl;
   
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
            cout << "Введите число для вставки: ";
            cin >> a;
            queue.push(a);
            break;
        }
        case 2:
        {
            cout << "Значение удаленного головного элемента: " << queue.pop() << endl;
            break;
        }
        case 3:
        {
            cout << "Значение головного элемента: " << queue.peek() << endl;
            break;
        }

        case 4:
            cout << "Длина очереди: " << queue.get_size() << endl;
            break;
       
        default:
            cout << "Введено недопустимое значение" << endl;
        }
        cin >> opt;
    }
    return 0;
}