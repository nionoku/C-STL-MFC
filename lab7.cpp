/*
Kondrev Alexander
23531-21

Разработать функтор, позволяющий собирать статистику о последовательности
целых чисел (послед может содержать числа от -500 до 500). Функтор после
обработки последовательности алгоритмом for_each должен предоставлять
следующую статистику:
a. Максимальное число в последовательности
b. Минимальное число в последовательности
c. Среднее число в последовательности
d. Количество положительных чисел
e. Количество отрицательных чисел
f. Сумму нечетных элементов последовательности
g. Сумму четных элементов последовательности
h. Совпадают ли первый и последний элементы последовательности
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Functor {
	private:
		// минимальное число в последовательности, максимальное, среднее, количество чисел > 0, < 0
		// количество четных и не четных;
		int sum = 0, max, min, mid, cntPositive = 0, cntNegative = 0, cntChet = 0, cntNechet = 0;
		bool equalFirstLast = false;
		
	public:
		void operator() (vector<int> list) {
			max = list[0];
			min = list[0];
			
			equalFirstLast = list[0] == list[list.size() - 1];
			
			for_each(list.begin(), list.end(), [&](int num) {
				sum += num;
				
				if (max < num)
					max = num;
				
				if (min > num)
					min = num;
				
				if (num >= 0)
					cntPositive++;
				else
					cntNegative++;
				
				if (num % 2 == 0)
					cntChet++;
				else
					cntNechet++;
			});
			
			mid = sum / list.size();
			
			cout << "Max: " << max << " Min: " << min << " Middle: " << mid << " " << sum << " " << list.size() << endl;
			cout << "Positive: " << cntPositive << " Negative: " << cntNegative << endl;
			cout << "Chet: " << cntChet << " Nechet: " << cntNechet << endl;
			cout << "First equal last?: " << equalFirstLast << endl;
		}
};

int main() {
	vector<int> values;
	
	srand(time(0));
	for (int i = 0; i < 20; i++)
		values.push_back(rand() % 1000 - 500);
	
	Functor func;
	func(values);
	
	return 0;
}
