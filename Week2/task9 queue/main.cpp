/*
 [RU]

Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить 
в конец и уходить оттуда. Более того, иногда некоторые люди могут прекращать и начинать 
беспокоиться из-за того, что очередь не продвигается.

Реализуйте обработку следующих операций над очередью:

- WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
- QUIET i: пометить i-го человека как успокоившегося;
- COME k: добавить k спокойных человек в конец очереди;
- COME -k: убрать k человек из конца очереди;
- WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.

Формат ввода
Количество операций Q, затем описания операций.

Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.

Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Формат вывода
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.

Пример

Ввод

8
COME 5
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT


Вывод
1
2

*/
#include <iostream>
#include <vector>

using namespace std;

#define WORRY "WORRY"

#define QUIET "QUIET"

#define COME "COME"

#define WORRY_COUNT "WORRY_COUNT"

struct Person
{
    bool isWorry;
};

struct QueueOperation
{
    string type;
    int arg;
};

void PrintWorryPeoples(const vector<Person> &people)
{
    int worries = 0;

    for (Person person : people)
    {
        if (person.isWorry == true)
        {
            worries++;
        }
    }
    cout << worries << endl;
}

void ApplyOperation(vector<Person> &v, const QueueOperation operation)
{
    if (operation.type == WORRY)
    {
        v[operation.arg].isWorry = true;
    }
    else if (operation.type == QUIET)
    {
        v[operation.arg].isWorry = false;
    }
    else if (operation.type == COME)
    {

        int iterationCount = operation.arg < 0 ? -1 * operation.arg : operation.arg;

        for (int i = 0; i < iterationCount; i++)
        {
            if (operation.arg > 0)
            {
                v.push_back({false});
            }
            else
            {
                v.pop_back();
            }
        }
    }
}

int main()
{
    // Test

    vector<Person> queue = {};

    int operationCount;
    cin >> operationCount;

    for (int i = 0; i < operationCount; i++)
    {
        string operation;

        cin >> operation;

        if (operation != WORRY_COUNT)
        {
            int personId;
            cin >> personId;
            ApplyOperation(queue, {operation, personId});
        }
        else
        {
            PrintWorryPeoples(queue);
        }
    }

    return 0;
}
