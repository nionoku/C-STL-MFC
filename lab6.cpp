/*
Kondrev Alexander
23531-21

Написать программу, которая выполняет следующие действия:
a. Читает содержимое текстового файла
b. Выделяет слова, словом считаются последовательность символов
разделенных пробелами и/или знаками табуляции и/или символами новой
строки
c. Вывести список слов присутствующий в тексте без повторений (имеется в
виду, что одно и то же слово может присутствовать в списке только один раз)
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

// прототипы функций
/* Функция читает текст из файла */
string readFile(string path);
/* Функция парсит слова в файле */
void parseString(string str);

int main() {
	parseString(readFile("D:\\develop\\C++\\lab6-algorithms\\lab6.cpp"));
	return 0;
}

string readFile(string path) {
	ifstream file;
	file.open(path);
	
	if (file.is_open()) {
		string res( (istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()) );

		cout << "Original strings" << endl << res << endl;
		
		return res;
	} else {
		return NULL;
	}
}

void parseString(string str) {
	istringstream buf(str);
    istream_iterator<string> beg(buf), end;

	vector<string> wordsVector (beg, end);
	
	sort(wordsVector.begin(), wordsVector.end());
	wordsVector.erase(unique(wordsVector.begin(), wordsVector.end()), wordsVector.end());

	cout << "Unique words" << endl;
	for_each(wordsVector.begin(), wordsVector.end(), [&](string elem){ cout << elem << " "; });
}
