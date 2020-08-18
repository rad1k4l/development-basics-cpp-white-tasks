/*


У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:

ADD i s
Назначить дело с названием s на день i текущего месяца.

DUMP i
Вывести все дела, запланированные на день i текущего месяца.

NEXT
Перейти к списку дел на новый месяц. При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся и становится активным (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список. После выполнения данной команды новый список дел и следующий месяц становятся текущими, а работа со старым списком дел прекращается. При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:

если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.
Замечания
Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца. Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
Формат ввода
Сначала число операций Q, затем описания операций.

Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.

Формат вывода
Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.

Пример

Ввод

12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28



Вывод

1 Salary
2 WalkPreparations Walk
0
0
2 WalkPreparations Walk
3 WalkPreparations Walk Payment

*/

#include <iostream>
#include <vector>

using namespace std;


int numberOfDays[12] = {
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
};

int currentMonth = 0;


#define ADD		"ADD"

#define DUMP	"DUMP"

#define NEXT	"NEXT"


struct CalendarItem
{
	int day;

	string task;

};


vector<CalendarItem> GetTasks(int day, const vector<CalendarItem>& calendar) {
	vector<CalendarItem> tasks = {};

	for (auto& item : calendar)
	{
		if (item.day == day)
		{
			tasks.push_back(item);
		}
	}
	return tasks;
}

void PrintTasks(int day, const vector<CalendarItem>& calendar) {
	vector<CalendarItem> tasks = GetTasks(day, calendar);

	cout << tasks.size() << ' ';

	for (auto& task : tasks)
	{
		cout << task.task << ' ';
	}
	cout << endl;
}

int GetNextMonthIndex() {
	if (currentMonth == 11) {
		return 0;
	}
	else {
		return currentMonth + 1;
	}
}

int GetPrevMonthIndex() {
	if (currentMonth == 0) {
		return 11;
	}
	else {
		return currentMonth - 1;
	}
}
void RelocateTasks(vector<CalendarItem>& calendar, int from, int to) {
	for (auto& item : calendar)
	{
		if (item.day == from)
		{
			item.day = to;
		}
	}
}


void Next(vector<CalendarItem>& calendar) {
	if (numberOfDays[currentMonth] > numberOfDays[GetNextMonthIndex()])
	{
		
		for (int i = numberOfDays[GetNextMonthIndex()] + 1; i <= numberOfDays[currentMonth]; i++)
		{
			RelocateTasks(calendar, i,  numberOfDays[GetNextMonthIndex()]);
		}
	}

	currentMonth = GetNextMonthIndex();
}


int main()
{
	// Test


	vector<CalendarItem> calendar = {};

	int operationCount;
	cin >> operationCount;

	for (int i = 0; i < operationCount; i++)
	{
		string operation;

		cin >> operation;

		if (operation == ADD)
		{
			// day
			int i;
			cin >> i;

			// daily task name
			string s;
			cin >> s;

			calendar.push_back({ i , s });
		}
		else if (operation == DUMP) {
			int i;
			cin >> i;

			PrintTasks(i, calendar);

		}
		else if (operation == NEXT) {
			Next(calendar);
		}
	}

	return 0;
}