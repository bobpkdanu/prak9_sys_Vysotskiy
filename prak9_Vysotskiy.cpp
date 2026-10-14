 #include <iostream>
using namespace std;

void increaseVol(double* data, int size)
{
	double k;
	cout << "Введите коэффициент увеличения: " << endl;
	cin >> k;

	for (int i = 0; i < size; i++)
	{
		data[i] = data[i] * k;
	}
}

void decreaseVol(double* data, int size)
{
	double k;
	cout << "Введите коэффициент уменьшения: " << endl;
	cin >> k;

	for (int i = 0; i < size; i++)
	{
		data[i] = data[i] / k;
	}
}

void resetSmallVal(double* data, int size)
{
	double min;
	cout << "Введите минимальное значение амплитуды: " << endl;
	cin >> min;
	for (int i = 0; i < size; i++)
	{
		if (data[i] < min)
		{
			data[i] = 0;
		}
	}
}

void limitAmp(double* data, int size)
{
	double max;

	cout << "Введите максимальное значение амплитуды: " << endl;
	cin >> max;

	for (int i = 0; i < size; i++)
	{
		if (data[i] > max)
		{
			data[i] = max;
		}
	}
}

void applyProcessing(double* data, int size, void(*processor)(double*, int))
{
	if (processor != nullptr)
	{
		processor(data, size);
	}
}

void input(double* data, int size)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 100;
	}
}

void show(double* data, int size)
{
	cout << "Амплитуды: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " " << endl;
	}
}

int main()
{
	const int maxsize = 100;
	double data[maxsize];
	double newdata[maxsize];
	int size = 0;

	setlocale(LC_ALL, "Ru");
	void (*processors[])(double*, int) = {
		increaseVol,
		decreaseVol,
		resetSmallVal,
		limitAmp
	};
	int choice;
	srand(time(NULL));
	do {
		cout << "Выберите действие: " << endl;
		cout << "1. Ввести данные" << endl;
		cout << "2. Показать данные" << endl;
		cout << "3. Увеличить громкость" << endl;
		cout << "4. Уменьшить громкость" << endl;
		cout << "5. Обнулить малые значения" << endl;
		cout << "6. Задать максимальное значение" << endl;
		cout << "7. Выход" << endl;
		cin >> choice;
		if (choice < 1 || choice > 7)
		{
			cout << "Это мы ещё посмотрим";
			return 0;
		}
		else if (choice == 1)
		{
			cout << "Введите размер массива: " << endl;
			cin >> size;
			if (size < 0 || size > maxsize)
			{
				cout << "Неверно введён размер массива" << endl;
				return 0;
			}
			input(data, size);

			for (int i = 0; i < size; i++)
			{
				newdata[i] = data[i];
			}
			cout << "Данные записаны" << endl;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < size; i++)
			{
				cout << "Амплитуда " << i << ":" << data[i] << endl;
			}
		}
		else if (choice == 3)
		{
			applyProcessing(data, size, *processors[0]);
			/*increaseVol(data,size);*/
		}
		else if (choice == 4)
		{
			applyProcessing(data, size, *processors[1]);
			/*decreaseVol(data, size);*/
		}
		else if (choice == 5)
		{
			applyProcessing(data, size, *processors[2]);
			//resetSmallVal(data, size);
		}
		else if (choice == 6)
		{
			applyProcessing(data, size, *processors[3]);
			/*limitAmp(data, size);*/
		}
		else if (choice == 7)
		{
			cout << "Пока" << endl;
		}
		else 
		{
			cout << "Это мы ещё посмотрим" << endl;
		}
	} while (choice != 7);

	return 1;
}
