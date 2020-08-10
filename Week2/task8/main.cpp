/**
 * 
 * 
 *  [RU]
 * 
 *  Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней (в нумерации с нуля) со значением температуры
 *  выше среднего арифметического за все N дней.
 *
 *  Гарантируется, что среднее арифметическое значений температуры является целым числом.
 *  
 *  Формат ввода
 *  Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
 *  
 *  Формат вывода
 *  Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.
 * 
 *  ----------------------------------------------------
 * 
 *  [EN]
 * 
 *  The temperature values observed for N consecutive days are given. Find the number
 *  of days (numbered from zero) with a temperature value higher than the arithmetic
 *  average for all N days.
 * 
 *  It is guaranteed that the arithmetic mean of the temperature values is an integer.
 * 
 *  Input format
 *  Enter the number N, then N non-negative integers — the temperature values on the 0th, 1st, ... (N-1) th day.
 *  
 *  Output format
 *  The first number K is the number of days when the temperature value is higher 
 *  than the arithmetic average. Then K integers are the numbers of these days.
 *  
 *  Example 
 *  
 *  Input : 
 *  5
 *  7 6 3 0 9
 *  
 *  Output: 
 *  3
 *  0 1 4
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;

int VectorSum(vector<int> vect)
{
    int sum = 0;
    for (int s : vect)
    {
        sum += s;
    }

    return sum;
}

void PrintIntVector(vector<int> v, string separator = " ")
{
    for (int s : v)
    {
        cout << s << separator;
    }
}

int main()
{
    // Test
    int n;

    cin >> n;

    vector<int> temperatures(n);

    for (int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }

    int arithmeticMean = VectorSum(temperatures) / n;

    vector<int> days = {};

    for (int i = 0; i < temperatures.size(); i++)
    {
        if (temperatures[i] > arithmeticMean)
        {
            days.push_back(i);
        }
    }

    cout << days.size() << endl;

    PrintIntVector(days);

    return 0;
}