/*
Kondrev Alexander
23531-21

Ниже приведен интерфейс класса очереди с приоритетами, который
функционирует следующим образом.
В очередь могут быть добавлены элементы, каждому элементу при добавлении
присваивается один из трех уровней приоритета (low, normal, high)
Элементы из очереди извлекаются в соответствии с их приоритетами (сначала
извлекаются элементы с приоритетом high, потом normal, потом low), элементы с
одинаковыми приоритетами извлекаются из очереди в порядки их поступления.
В очереди также может происходить операция акселерации – все элементы с
приоритетом low находящиеся в момент акселерации в очереди увеличивают свой
приоритет до high и «обгоняют» элементы с приоритетом normal.

Реализовать этот класс, используя list или deque. Объяснить свой выбор.
Протестируете программу, добавьте отладочный вывод, показывающий, что класс
работает правильно.
*/

#include <string>
#include <list>
#include <iostream>
#include <conio.h>

using namespace std;

typedef enum {
	LOW,
	NORMAL,
	HIGH
} Priority;

typedef struct {
	string name;
} Element;

class PriorityQueue {
	
	private:
		list<Element> lowPriority;
		list<Element> normalPriority;
		list<Element> highPriority;
	
	public:
		// конструктор
		PriorityQueue() {
			cout << ">> Queue was created" << endl;
		}
		
		// деструктор
		~PriorityQueue() {
			cout << ">> Queue was destroyed" << endl;
		}
		
		// метод добавляет элемент в очередь
		void put(Element &element, Priority priority) {
			switch (priority) {
				case LOW:
					lowPriority.push_back(element);
					break;
					
				case NORMAL:
					normalPriority.push_back(element);
					break;
					
				case HIGH:
					highPriority.push_back(element);
			}
		}
		
		// метод возвращает элемент очереди с наивысшим приоритетом
		// добавленный в очередь первым
		Element pop() {
			Element returned;
			
			if (!highPriority.empty()) {
				returned = highPriority.front();
				highPriority.pop_front();
			} else if (!normalPriority.empty()) {
				returned = normalPriority.front();
				normalPriority.pop_front();
			} else if (!lowPriority.empty()) {
				returned = lowPriority.front();
				lowPriority.pop_front();
			}
		
			return returned;
		}
		
		// метод выполняет акселерацию
		/* В очереди также может происходить операция акселерации – все элементы с
		приоритетом low находящиеся в момент акселерации в очереди увеличивают свой
		приоритет до high и «обгоняют» элементы с приоритетом normal. */
		void accelerate() {
			if (!lowPriority.empty()) {
				highPriority.splice(highPriority.end(), lowPriority);
				lowPriority.clear();
			}
		}
};

int main() {
	Element element1;
	element1.name = "Low";
	Element element2;
	element2.name = "Normal";
	Element element3;
	element3.name = "High";
	
	PriorityQueue queue;
	queue.put(element1, LOW);
	queue.put(element2, NORMAL);
	queue.put(element3, HIGH);
	
	queue.accelerate();
	cout << queue.pop().name << endl;
	cout << queue.pop().name << endl;
	cout << queue.pop().name << endl;
	
	_getch();
	
	return 0;
}
