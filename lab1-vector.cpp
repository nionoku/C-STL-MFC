/*
Kondrev Alexander
23531-21
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include "string.h"

using namespace std;

// прототипы функций
template <typename T>
void printVector(vector<T> &arr);
// 1
/*
Напишите алгоритм сортировки (любой простейший) содержимого вектора целых
чисел, используя оператор operator[].
*/
void taskOne(vector<int> &arr);
// 2
/*
Напишите алгоритм сортировки (любой простейший) содержимого вектора целых
чисел, используя метод at().
*/
void taskTwo(vector<int> &arr);
// 3
/*
Напишите алгоритм сортировки (любой простейший) содержимого вектора целых
чисел, используя для доступа к содержимому вектора только итераторы. Для
работы с итераторами допустимо использовать только операторы получения
текущего элемента и перехода в следующему (подсказка, можно сохранять копию
итератора указывающего на некоторый элемент). 
*/
void taskThree(vector<int> &arr);
// 4
/*
Прочитайте во встроенный массив С содержимое текстового файлы, скопируйте
данные в вектор одной строкой кода (без циклов и алгоритмов STL)
*/
void taskFour(char *path);
// 5
/*
Напишите программу, сохраняющую в векторе числа, полученные из стандартного
ввода (окончанием ввода является число 0). Удалите все элементы, которые
делятся на 2 (не используете стандартные алгоритмы STL), если последнее число 1.
Если последнее число 2, добавьте после каждого числа которое делится на 3 три
единицы
*/
void taskFive();
// 6
/* 
Напишите функцию void fillRandom(double* array, int size) заполняющую массив
случайными значениями в интервале от -1.0 до 1.0. Заполните с помощью заданной
функции вектора размером 5,10,25,50,100 и отсортируйте его содержимое (с
помощью любого разработанного ранее алгоритма модифицированного для
сортировки действительных чисел)
*/
void taskOneDouble(vector<double> &arr);
void fillRandom(double* array, int size);
void taskSix(int arraySize);

int main() {
	// -- 1, 2, 3, 5 --
	// Обьявляем коллекцию и наполняем ее 5ю значениями
	/* vector<int> list;
	list.push_back(4);
	list.push_back(7);
	list.push_back(2);
	list.push_back(1);
	list.push_back(9);
	
	cout << "Init collection" << endl;
	printVector(list);
	
	cout << "Sorted collection" << endl; */
//	taskOne(list);
//	taskTwo(list);
//	taskThree(list);
//	taskFive();
	// -- 1, 2, 3, 5 --

	// -- 4, 6 --
//	taskFour();
//	taskSix(5);
	// -- 4, 6 --
	
	return 0;
}

void taskOne(vector<int> &arr) {
	for(int i = 1; i < arr.size() - 1; i++) {
		int x = arr[i];
		int j = i;
		
		while((j > 0) && (arr[j-1] > x)) {
			arr[j] = arr[j-1];
			j--;
		}
		
		arr[j] = x;
	}
	
	printVector(arr);
}

void taskOneDouble(vector<double> &arr) {
	for(int i = 1; i < arr.size() - 1; i++) {
		double x = arr[i];
		int j = i;
		
		while((j > 0) && (arr[j-1] > x)) {
			arr[j] = arr[j-1];
			j--;
		}
		
		arr[j] = x;
	}
	
	printVector(arr);
}

void taskTwo(vector<int> &arr) {
	try {
		for(int i = 1; i < arr.size() - 1; i++) {
			int x = arr.at(i);
			int j = i;
		
			while((j > 0) && (arr.at(j-1) > x)) {
				arr.at(j) = arr.at(j-1);
				j--;
			}
		
			arr.at(j) = x;
		}
		
		printVector(arr);
	} catch(out_of_range) {
		cout << "out_of_range exception" << endl;
	}
}

void taskThree(vector<int> &arr) {
	// инициализируем итератор
	vector<int>::iterator iterator = arr.begin();
	
	while(iterator != arr.end()) {
		vector<int>::iterator iterable = iterator + 1;
		
		while(iterable != arr.end()) {
			if (*iterator > *iterable) {
				arr.erase(iterable);
				arr.insert(iterator, *iterable);
			}
			
			iterable++;
		}
		
		iterator++;
	}
	
	printVector(arr);
}

void taskFour(char *path) {
	FILE *f = fopen(path, "rb");
	char lines[5][100];
	
	for(int i = 0; i < 5; i++) {
		fgets(lines[i], 100, f);
		char *pointer = strrchr(lines[i], '\n');
		
		if (pointer)
			*pointer = '\0';
	}
	
	// записываем значения из массива в вектор
	vector<char *> vectorLines(lines, lines + 5);
	
	printVector(vectorLines);
}

void taskFive() {
	vector<int> arr;
	int temp;
	
	while(true) {
		cin >> temp;
		
		if (temp != 0)
			arr.push_back(temp);
		else
			break;
	}
	
	if (arr[arr.size() - 1] == 1) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % 2 == 0) {
				// т.к метода удаления по индексу нету, сэмулируем его через итератор
				// к началу итератора прибавим текущий индекс
				arr.erase(arr.begin() + i);
			}
		}
	} else if (arr[arr.size() - 1] == 2) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % 3 == 0) {
				arr[i] *= 1000;
				arr[i] += 111;
			}
		}
	}
	
	printVector(arr);
}

void fillRandom(double* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = ((2.0) * ((double)rand() / RAND_MAX)) - 1.0;
}

void taskSix(int arraySize) {
	// объявляем массив
	double arr[arraySize];
	// заполняем массив случайными числами
	fillRandom(arr, arraySize);
	// создаем вектор на основе массива
	vector<double> vector(arr, arr + arraySize);
	
	cout << "Init collection" << endl;
	printVector(vector);
	
	// сортируем вектор
	taskOneDouble(vector);
	
	cout << "Sorted collection" << endl;
	printVector(vector);
}

// функция печатает вектор
template <typename T>
void printVector(vector<T> &arr) {
	// инициализируем итератор
	typename vector<T>::iterator iterator = arr.begin();
	
	// перебираем вектор
	while(iterator != arr.end()) {
		cout << *iterator << " ";
		iterator++;
	}
	
	cout << endl;
}
