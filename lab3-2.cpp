/*
Kondrev Alexander
23531-21

Разработайте программу, которая
a. Заполняет list<int> 15 случайными значениями от 1 до 20, список может
содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1.
2, 3, 4, 5, 7, 14)
b. Выводит содержимое списка в следующем порядке: первый элемент,
последний элемент, второй элемент, предпоследний элемент, тритий
элемент и т.д.
Например если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид
1 8 2 7 3 6 4 5
Подсказка: можно использовать рекурсию и двунаправленные итераторы
*/

#include <list>
#include <iostream>

using namespace std;

// прототипы функций
/* Функция заполняет list рандомными значениями */
list<int> fillList(int size);
/* функция выводит список элементов первый-последний к центру */
void printList(list<int> list);

int main() {
	printList(fillList(20));
	return 0;
}

list<int> fillList(int size) {
	list<int> randomValuesList;
	
	while(randomValuesList.size() < size) {
		randomValuesList.push_back(rand() % 20 + 1);
	}
	
	list<int>::iterator iter = randomValuesList.begin();
	
	while(iter != randomValuesList.end()) {
	    cout << *iter << " ";   
	    iter++;
	}
	
	cout << endl;
	
	return randomValuesList;
}

// функция печатает лист
void printList(list<int> list) {
	// инициализируем прямой итератор
	std::list<int>::iterator starter = list.begin();
	// инициализируем обратный итератор
	std::list<int>::reverse_iterator ender = list.rbegin();
	
	// перебираем все элементы list'a
	// если количество элементов четное - выводится весь массив
	for (int i = 0; i < list.size() / 2; i++) {
		cout << *(starter++) << " " << *(ender++) << " ";
	}
	
	// если количество элементов не четное - нужно дополнительно вывести
	// центальный элемент list'a
	if (list.size() % 2 != 0)
		cout << *starter;
}
