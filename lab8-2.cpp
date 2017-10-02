/*
Kondrev Alexander
23531-21

Разработать программу, которая:
a. Реализует иерархию геометрических фигур состоящую из:
i. Класс Shape.
1. Содержит информацию о положении центра фигуры
(координаты x и y).
2. Содердит метод IsMoreLeft, позволяющий определить
расположена ли данная фигура левее (определяется по
положению центра) чем фигура переданная в качестве
аргумента
3. Содердит метод IsUpper, позволяющий определить
расположена ли данная фигура выше (определяется по
положению центра) чем фигура переданная в качестве
аргумента
4. Определяет чисто виртаульную функцию рисования Draw
(каждая фигура в реализации этой функци должна выводить
на стандартный вывод свое название и положение цента)
ii. Класс Circle производный от класса Shape
1. Реализует Draw
iii. Класс Triangle производный от класса Shape
1. Реализует Draw
iv. Класс Square производный от класса Shape
1. Реализует Draw
b. Содержит список list<Shape*>, заполенный указателями на различные
фигуры
c. С помощью стандартных алгоритмов и адаптеров выводит (Draw) все
фигуры
d. С помощью стандартных алгоритмов и адаптеров сортирует список по
положению центра слева-направо (имется в виду, что в начале списка
должны идти фигуры находящиеся левее, координата x ) и выводит фигуры
(Draw)
e. С помощью стандартных алгоритмов и адаптеров сортирует список по
положению центра справа-налево и выводит фигуры
f. С помощью стандартных алгоритмов и адаптеров сортирует список по
положению центра сверху-вниз и выводит фигуры
g. С помощью стандартных алгоритмов и адаптеров сортирует список по
положению центра снизу-вверх и выводит фигуры
*/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdlib.h>

using namespace std;

struct Point {
	int x, y;
};

Point getRandomPoint() {
	Point point;
	point.x = rand() % 20 - 10;
	point.y = rand() % 20 - 10;
	return point;
}

class Shape {
	private:
		string figure;
		Point center;
		
	public:
		Shape(string fig, Point cent) {
			figure = fig;
			center = cent;
		}
		
		~Shape() {
			
		}
		
		bool isMoreLeft(Shape *shape) {
			if (center.x < shape->getCenter().x)
				return true;
			else
				return false;
		}
		
		bool isUpper(Shape *shape) {
			if (center.y > shape->getCenter().y)
				return true;
			else
				return false;
		}
		
		void draw() {
			cout << "Figure: " << figure << "; center: (" << center.x << "," << center.y << ");" << endl;
		}
		
		Point getCenter() {
			return center;
		}
};

class Circle : public Shape {
	public:
		Circle(Point center) : Shape("Circle", center) { }
};

class Triangle : public Shape {
	public:
		Triangle(Point center) : Shape("Triangle", center) { }
};

class Square : public Shape {
	public:
		Square(Point center) : Shape("Square", center) { }
};

int main() {
	srand(time(NULL));
	
	list<Shape*> figures;
	
	Shape circle = Circle(getRandomPoint());
	figures.push_back(&circle);
		
	Shape triangle = Triangle(getRandomPoint());
	figures.push_back(&triangle);
		
	Shape square = Square(getRandomPoint());
	figures.push_back(&square);
	
	// выводим фигуры методом draw()
	cout << "Started list:" << endl;
	for_each(figures.begin(), figures.end(), [&](Shape *shape) { shape->draw(); });
	
	// сортируем фигуры слева-направо
	figures.sort([](Shape *a, Shape *b) { return a->isMoreLeft(b); });
	cout << endl << "Sorted left-right list:" << endl;
	for_each(figures.begin(), figures.end(), [&](Shape *shape) { shape->draw(); });
	
	// сортируем фигуры справа-налево
	figures.sort([](Shape *a, Shape *b) { return !a->isMoreLeft(b); });
	cout << endl << "Sorted right-left list:" << endl;
	for_each(figures.begin(), figures.end(), [&](Shape *shape) { shape->draw(); });
	
	// сортируем фигуры сверху-вниз
	figures.sort([](Shape *a, Shape *b) { return a->isUpper(b); });
	cout << endl << "Sorted up-down list:" << endl;
	for_each(figures.begin(), figures.end(), [&](Shape *shape) { shape->draw(); });
	
	// сортируем фигуры снизу-вверх
	figures.sort([](Shape *a, Shape *b) { return !a->isUpper(b); });
	cout << endl << "Sorted down-up list:" << endl;
	for_each(figures.begin(), figures.end(), [&](Shape *shape) { shape->draw(); });
	return 0;
}
