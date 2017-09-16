/*
Author: Kondrev Alexander
23531-21

Задание:
Разработать программу, которая должна сделать следующее:
1. Прочитать содержимое текстового файла. Файл может содержать:
a. Слова – состоят из латинских строчных и заглавных букв, а также цифр,
длинна слова должна быть не более 20 символов
b. Знаки препинания – «.», «,» «!» «?» «:» «;»
c. Пробельные символы – пробел, табуляция, символ новой строки.
2. Отформатировать текст следующим образом:
a. Не должно быть пробельных символов отличных от пробела
b. Не должно идти подряд более одного пробела
c. Между словом и знаком препинания не должно быть пробела
d. После знака препинания всегда должен идти пробел
e. Слова длиной более 10 символов заменяются на слово «Vau!!!»
3. Преобразовать полученный текст в набор строка, каждая из которых содержит
целое количество строк (слово должно целиком находиться в строке) и ее длинна
не превышает 40 символов.
*/

#include "string.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <regex>
#include <conio.h>

using namespace std;

// прототипы функций
string replaceMoreSpaces(string str);
string replaceSpacesPunchMarks(string str);
string replaceSpacesSymbols(string str);
string replaceWords(string str);
/* Функция читает файл */
string readFile(string path);
/* Функция форматирует строку следующим видом:
a. Не должно быть пробельных символов отличных от пробела
b. Не должно идти подряд более одного пробела
c. Между словом и знаком препинания не должно быть пробела
d. После знака препинания всегда должен идти пробел
e. Слова длиной более 10 символов заменяются на слово «Vau!!!» */
string formatter(string str);
/* Функция преобразует полученный текст в набор строка, каждая из которых содержит
целое количество строк (слово должно целиком находиться в строке) и ее длинна
не превышает 40 символов. */
void stringDilimiter(string str, int wordCount);
/* Функция печатает вектор */
template <typename T>
void printVector(vector<T> &arr);

int main() {
	stringDilimiter(formatter(readFile(/*"D:\input.txt"*/"lab2.cpp")), 40);
	
	_getch();
	return 0;
}

string readFile(string path) {
	ifstream file;
	file.open(path);
	
	if (file.is_open()) {
		string res( (istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()) );
		
		cout << "Input strings:" << endl << res << endl;
		
		return res;
	} else {
		return NULL;
	}
}

string formatter(string str) {
	string temp = str;
	
	temp = replaceSpacesPunchMarks(temp);
	temp = replaceSpacesSymbols(temp);
	temp = replaceWords(temp);
	temp = replaceMoreSpaces(temp);
	
	return temp;
}

string replaceSpacesPunchMarks(string str) {
	// массив знаков препинания
	char punctMarks[] = { ',', '.', '!', '?', ':', ';' };
	int punctMarksArrSize = sizeof(punctMarks) / sizeof(punctMarks[0]);
	
	string result = str;
	
	// добавляем пробелы после знаков препинания
	for (int i = 0; i < punctMarksArrSize; i++) {
		int pos;
		
		while ((pos = result.find(punctMarks[i], pos + 1)) != result.npos) {
			try {
//				cout << punctMarks[i] << " " << pos  << " " << result[pos] << endl;
				// если после знака препинания не идет пробел..
				if (result.compare(pos + 1, 1, " ") != 0) {
					// ставим пробел после знака препинания
					result.insert(pos + 1, " ");
				}
			} catch(out_of_range) {
				cout << "#1 out of range exception" << endl;
			}
		}
	}
	
	// удаляем пробелы перед знаками препинания
	for (int i = 0; i < punctMarksArrSize; i++) {
		int pos;
		
		while ((pos = result.find(punctMarks[i], pos + 1)) != result.npos) {
			try {
				// если перед знаком препинания стоит пробел..
				if (result.compare(pos - 1, 1, " ") == 0)
					// удаляем пробел перед знаком препинания
					result.erase(pos - 1, 1);
			} catch(out_of_range) {
				cout << "#2 out of range exception" << endl;
			}
		}
	}
	
	return result;
}

string replaceSpacesSymbols(string str) {
	char spacesMarks[] = { '\t', '\n' };
	string result = str;
	
	for (int i = 0; i < sizeof(spacesMarks) / sizeof(spacesMarks[0]); i++) {
		int pos;
		
		// удаляем пробельные символы, отличные от пробела
		while ((pos = result.find(spacesMarks[i])) != result.npos) {
			result.erase(pos, 1);
		}
	}
	
	return result;
}

string replaceWords(string str) {
	regex wordReg("[\\w]{10,}");
	string word = "Vau!!!";
	
	return regex_replace(str, wordReg, word);
}

string replaceMoreSpaces(string str) {
	// удаляем дублирующиеся пробелы
	regex spaceReg("[\\s]{2,}");
	string space = " ";
	
	return regex_replace(str, spaceReg, space);
}

void stringDilimiter(string str, int wordCount) {
	vector<string> vector;
	// индекст последней позиции, смещения, конца линии и текущая ширина
	int lastPos = 0, offset = 0, end = 0, width;
	
	while (true) {
		width = wordCount;
		end = lastPos + wordCount;
		
		if (end < str.size()) {
			offset = str.rfind(" ", end);
			
			if (offset != str.npos)
				width = width - (end - offset);
		}
		
		vector.push_back(str.substr(lastPos, width));
		lastPos = lastPos + width;
	
		if (lastPos >= str.size())
			break;
	}
	
	cout << endl << "Output strings:" << endl;
	printVector(vector);
}

template <typename T>
void printVector(vector<T> &arr) {
	// инициализируем итератор
	typename vector<T>::iterator iterator = arr.begin();
	
	// перебираем вектор
	while(iterator != arr.end()) {
		cout << *iterator << endl;
		iterator++;
	}
	
	cout << endl;
}
