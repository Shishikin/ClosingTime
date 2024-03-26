#include <iostream> 

#ifdef _WIN32
#include <windows.h>
#endif

enum  Day {
	Monday, Tuesday, Wednesday, Thursday,
	Friday, Saturday, Sunday
};

int closing_time(Day day_of_the_week);

std::ostream& operator << (std::ostream& out, const Day& day)
{
	switch (day)
	{
	case 0: out << "Понедельник"; break;
	case 1: out << "Вторник"; break;
	case 2: out << "Среда"; break;
	case 3: out << "Четверг"; break;
	case 4: out << "Пятница"; break;
	case 5: out << "Суббота"; break;
	case 6: out << "Воскресенье"; break;
	}
	return out;
}

// Главная функция 
int main()
{
#ifdef _WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif

	// Печать заголовка таблицы 
	std::cout.width(17);
	std::cout << "ДЕНЬ";
	std::cout.width(19);
	std::cout << "ВРЕМЯ ЗАКРЫТИЯ \n\n";
	// Печать таблицы от понедельника (Day::Monday) до 
	// воскресенья (Day::Sunday) 
	for (int count = static_cast<int>(Day::Monday);
		count <= static_cast<int>(Day::Sunday); count++)
	{
		std::cout.width(19);
		std::cout << static_cast<Day>(count);
		std::cout.width(9);
		std::cout << closing_time(static_cast<Day>(count)) << ":00\n";
	}
	return 0;
}
// Конец главной функции 
// Функция, возвращающая время закрытия магазина 
// в заданный день недели 
int closing_time(Day day_of_the_week)
{
	switch (day_of_the_week)
	{
	case Wednesday:
		return 20;
	case Saturday:
		return 17;
	case Sunday:
		return 13;
	default:
		return 18;
	}
}