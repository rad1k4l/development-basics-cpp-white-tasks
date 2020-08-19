/*
Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:

CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
ABOUT country — вывод столицы страны country.
DUMP — вывод столиц всех стран.
Формат ввода
В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов. Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Выведите результат обработки каждого запроса:

В ответ на запрос CHANGE_CAPITAL country new_capital выведите
Introduce new country country with capital new_capital, если страны country раньше не существовало;
Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
В ответ на запрос RENAME old_country_name new_country_name выведите
Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.
В ответ на запрос ABOUT country выведите
Country country doesn't exist, если страны с названием country не существует;
Country country has capital capital, если страна country существует и имеет столицу capital.
В ответ на запрос DUMP выведите
There are no countries in the world, если пока не было добавлено ни одной страны;
последовательность пар вида country/capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.


Пример 1

Ввод

6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP


Вывод

Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow


*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, string> country_to_capital;

    for (int i = 0; i < q; ++i)
    {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "CHANGE_CAPITAL")
        {

            string country, new_capital;
            cin >> country >> new_capital;
            if (country_to_capital.count(country) == 0)
            {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            }
            else
            {
                const string &old_capital = country_to_capital[country];
                if (old_capital == new_capital)
                {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                }
                else
                {
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                }
            }
            country_to_capital[country] = new_capital;
        }
        else if (operation_code == "RENAME")
        {

            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1)
            {
                cout << "Incorrect rename, skip" << endl;
            }
            else
            {
                cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] << " has been renamed to " << new_country_name << endl;
                country_to_capital[new_country_name] = country_to_capital[old_country_name];
                country_to_capital.erase(old_country_name);
            }
        }
        else if (operation_code == "ABOUT")
        {

            string country;
            cin >> country;
            if (country_to_capital.count(country) == 0)
            {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else
            {
                cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
            }
        }
        else if (operation_code == "DUMP")
        {

            if (country_to_capital.empty())
            {
                cout << "There are no countries in the world" << endl;
            }
            else
            {
                for (const auto &country_item : country_to_capital)
                {
                    cout << country_item.first << "/" << country_item.second << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}

