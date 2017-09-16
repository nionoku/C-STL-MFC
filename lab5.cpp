/*
Kondrev Alexander
23531-21

Написать программа, которая выполняет следующие действия:
a. Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2,
генерируются случайным образом в диапазоне от -5 до 5, str заполняется из
таблицы (таблица содержит 10 произвольных строк, индекс строки
генерируется случайным образом)
b. Выводит полученный вектор на печать
c. Сортирует вектор следующим образом:
i. По возрастанию key1
ii. Если key1 одинаковые, то по возрастанию key2
iii. Если key1 и key2 одинаковые, то по возрастанию длинны
строки str
d. Выводит полученный вектор на печать
DataStruct определена следующим образом:
typedef struct
{
	int key1;
	int key2;
	string str;
} DataStruct;
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// прототипы функций
typedef struct LabDataStruct;
/*
Заполняет vector<LabDataStruct> структурами LabDataStruct, при этом key1 и key2,
генерируются случайным образом в диапазоне от -5 до 5, str заполняется из
таблицы (таблица содержит 10 произвольных строк, индекс строки
генерируется случайным образом)
*/
vector<LabDataStruct> fillVector(int vectorSize);
/* функция печатает вектор */
void printVector(vector<LabDataStruct> arr);
/*
Сортирует вектор следующим образом:
1. По возрастанию key1
2. Если key1 одинаковые, то по возрастанию key2
3. Если key1 и key2 одинаковые, то по возрастанию длинны
строки str
*/
vector<LabDataStruct> sortVector(vector<LabDataStruct> vector);
/* Возвращает случайную строку из списка */
string getRandomString();

typedef struct LabDataStruct {
	int key1;
	int key2;
	string str;
	
	/* Если key1 и key2 одинаковые, то по возрастанию длинны строки str */
	bool operator<(const LabDataStruct& strc) {
		if ((key1 == strc.key1) && (key2 == strc.key2))
			return str.length() < strc.str.length();
		else if (key1 == strc.key1)
			return key2 < strc.key2;
		else
			return key1 < strc.key1;
	}
};

int main() {
	// [test]
	sortVector(fillVector(5));
	return 0;
}

vector<LabDataStruct> fillVector(int vectorSize) {
	vector<LabDataStruct> vector;
	
	// обновляем таймер рандомного счетчика
	srand(time(0));
	
	for (int i = 0; i < vectorSize; i++) {
		LabDataStruct structur;
		structur.key1 = rand() % 10 - 5;
		structur.key2 = rand() % 10 - 5;
		structur.str = getRandomString();
		
		vector.push_back(structur);
	}
	
	cout << "Original vector" << endl;
	printVector(vector);
	
	return vector;
}

vector<LabDataStruct> sortVector(vector<LabDataStruct> vector) {
	
	sort(vector.begin(), vector.end())
	
	cout << "Modifity vector" << endl;
	printVector(vector);
	
	return vector;
}

string getRandomString() {
	char* stringArray[] = { 
		"String 1",
		"String 2",
		"String 3",
		"String 4",
		"String 5",
		"String 6",
		"String 7",
		"String 8",
		"String 9",
		"String 10"
	};
	
	vector<string> vectorStrings(stringArray, stringArray + 10);
	
	int i = rand() % (vectorStrings.size() - 1);
	
	return vectorStrings[i];
}

void printVector(vector<LabDataStruct> arr) {
	// инициализируем итератор
	typename vector<LabDataStruct>::iterator iterator = arr.begin();
	
	// перебираем вектор
	while(iterator != arr.end()) {
		LabDataStruct strc = *iterator;
		cout << strc.key1 << " " << strc.key2 << " " << strc.str << endl;
		iterator++;
	}
	
	cout << endl;
}
