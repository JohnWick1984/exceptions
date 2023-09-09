// exceptions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class QueuePriority
{
private:
    int queue[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    QueuePriority() : size(0) {}

    void insert(int value, int priority)
    {
        if (size >= MAX_SIZE)
        {
            throw "Queue is overflow!"; // Бросаем строку как исключение
        }

        int index = size;
        while (index > 0 && priority < priorities[index - 1])
        {
            queue[index] = queue[index - 1];
            priorities[index] = priorities[index - 1];
            index--;
        }

        queue[index] = value;
        priorities[index] = priority;
        size++;
    }

    int extract()
    {
        if (size == 0)
        {
            throw "Queue is empty!"; // Бросаем строку как исключение
        }

        int value = queue[0];

        for (int i = 0; i < size - 1; i++)
        {
            queue[i] = queue[i + 1];
            priorities[i] = priorities[i + 1];
        }

        size--;
        return value;
    }
};

int main()
{
    QueuePriority queue;

    try
    {
        queue.insert(10, 2);
        queue.insert(20, 1);
        queue.insert(30, 3);

        cout << "Extracting from queue: " << queue.extract() << endl;
        cout << "Extracting from queue: " << queue.extract() << endl;
        cout << "Extracting from queue: " << queue.extract() << endl;
        cout << "Extracting from queue: " << queue.extract() << endl;
    }
    catch (const char* e)
    {
        cout << "Exception: " << e << endl;
    }

    return 0;
}
