#include <iostream>
using namespace std;
class queue
{
private:
	int* arr; //сделаем указатель на массив
	int head; //переменная для начала очереди(головы)
	int tail; //переменная для конца очереди(хвоста)
	int N = 10;
public:
	class Full {};
	class Empty {};
	queue()
	{
		head = 0;
		tail = 0;
		arr = new int[N];
	}
	queue(int m)
	{
		N = m + 1;
		head = 0;
		tail = 0;
		arr = new int[N];
	}
	~queue() //деструктор для освобождения памяти
	{
		delete[] arr;
	}
	void add_item(int a) //функция добавления элемента
	{
		if (head == (tail + 1) % N) //проверяем наличие места в очереди
			throw Full();
		else
		{
			arr[tail] = a; //записываем значение в массив
			tail = (tail + 1) % N; //присваиваем нашему “хвосту” номер последнего эл-та
		}
	}
	int extract_item() //функция извлечения элемента
	{
		if (head != tail) //проверяем наличие элементов в очереди
		{
			int a = arr[head]; //выводим на экран последний в очереди элемент
			head = (head + 1) % N; //присваиваем нашей “голове” номер следующего эл-та
			return a;
		}
		else
			throw Empty();
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int znach, o;
	bool r; //укажем логический тип данных для проверки логических условий
	cout << "Сколько будет элементов в очереди: ";
	cin >> o;
	queue one(o);
	do
	{
		cout << "Для добавление введите 1, для извлечения 0: ";
		cin >> r;
		if (r)
		{
			cout << "Введите значение: ";
			cin >> znach;
			try
			{
				one.add_item(znach);
			}
			catch (queue::Full)
			{
				cout << "Ошибка: переполнение очереди" << endl;
			}
		}
		else
		{
			cout << "Значение равно: ";
			try
			{
				cout << one.extract_item();;
			}
			catch (queue::Empty)
			{
				cout << "Ошибка: очередь пуста" << endl;
			}
			cout << endl;
		}
	} while (true);
	return 0;
}