/*
Kondrev Alexander
23531-21

Написать программу, которая выполняет следующие действия (все операции
должны выполняться с помощью стандартных алгоритмов):
a. Заполняет вектор геометрическими фигурами. Геометрическая фигура
может быть треугольником, квадратом, прямоугольником или пяти
угольником. Структура описывающая геометрическую фигуру определена
ниже,
b. Подсчитывает общее количество вершин всех фигур содержащихся в
векторе (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
c. Подсчитывает количество треугольников, квадратов и прямоугольников в
векторе
d. Удаляет все пятиугольники
e. На основании этого вектора создает vector<Point>, который содержит
координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент
этого вектора содержит координаты одной из вершину первой фигуры,
второй элемент этого вектора содержит координаты одной из вершину
второй фигуры и т.д.
f. Изменяет вектор так, чтобы он содержал в начале все треугольники, потом
все квадраты, а потом прямоугольники.
g. Распечатывает вектор после каждого этапа работы
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Прототипы функций
typedef struct Point;
typedef struct Shape;
// функция считает почти длину стороны
int sqrDist(Point a, Point b);
// функция печатает фигуры
void printFigures(vector<Shape> shapes);

struct Point {
	int x, y;
};

struct Shape {
	// количество вершин, для треугольника 3, для квадрата и
	// прямоугольника 4, для пяти угольника 5
	int vertexNum;
	
	// вектор содержащий координаты вершин фигуры
	// Для треугольника содержит 3 элемента
	// Для квадрата и прямоугольника содержит 4 элемента
	// Для пятиугольника 5 элементов
	vector<Point> vertexes;
	
	bool isTriangle() {
		return vertexNum == 3;
	}
	
	bool isSquare() {
		if (vertexNum == 4)
			return (sqrDist(vertexes[0], vertexes[1]) - sqrDist(vertexes[1], vertexes[2])
			+ sqrDist(vertexes[2], vertexes[3]) - sqrDist(vertexes[3], vertexes[0])) == 0;
		else
			return false;
	}
	
	bool isRectangle() {
		if (vertexNum == 4)
			return sqrDist(vertexes[0], vertexes[2]) == sqrDist(vertexes[1], vertexes[3]);
		else
			return false;
	}
};

int sqrDist(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
	vector<Shape> figures;
	
	srand(time(0));
	
	cout << "Unsorted vector" << endl;
	
	for (int i = 0; i < 10; i++) {	
		Shape shape;
		shape.vertexNum = rand() % 4 + 2;
		
		for (int j = 0; j < shape.vertexNum; j++) {
			Point point;
			point.x = rand() % 20 - 10;
			point.y = rand() % 20 - 10;
			
			shape.vertexes.push_back(point);
		}
		
		figures.push_back(shape);
	}
	
	// Добавим квадрат и прямоугольник для чистоты эксперимента
	// ---
	
	Shape shape;
	shape.vertexNum = 4;
	
	Point point;
	point.x = 0;
	point.y = 0;
	shape.vertexes.push_back(point);
	
	point.x = 5;
	point.y = 0;
	shape.vertexes.push_back(point);
	
	point.x = 5;
	point.y = 5;
	shape.vertexes.push_back(point);
	
	point.x = 0;
	point.y = 5;
	shape.vertexes.push_back(point);
	
	figures.push_back(shape);
	shape.vertexes.clear();
	
	// ---
	
	// ---
	
	point.x = 0;
	point.y = 0;
	shape.vertexes.push_back(point);
	
	point.x = 5;
	point.y = 0;
	shape.vertexes.push_back(point);
	
	point.x = 5;
	point.y = 10;
	shape.vertexes.push_back(point);
	
	point.x = 0;
	point.y = 10;
	shape.vertexes.push_back(point);
	
	figures.push_back(shape);
	
	// ---
	
	printFigures(figures);
	
	// удаляем многоугольники
	figures.erase(remove_if(figures.begin(), figures.end(), [&](Shape shape) { return shape.vertexNum >= 5; }), figures.end());
	
	printFigures(figures);
	
	// подсчитываем количество вершин у фигур
	int commonVertCount = 0;
	for_each(figures.begin(), figures.end(), [&](Shape shape) { commonVertCount += shape.vertexNum; });
	cout << endl << "Common vertex count: " << commonVertCount << endl;
	
	// подсчитываем треугольники, квадраты и прямоугольники
	int triangles = count_if(figures.begin(), figures.end(), [&](Shape shape) { return shape.isTriangle(); });
	int squares = count_if(figures.begin(), figures.end(), [&](Shape shape) { return shape.isSquare(); });
	int rectangles = count_if(figures.begin(), figures.end(), [&](Shape shape) { return shape.isRectangle(); }) - squares;
	
	cout << endl << "Triangles: " << triangles << " Squares: " << squares << " Rectangles: " << rectangles << endl;
	
	// сортируем фигуры
	sort(figures.begin(), figures.end(), [&](Shape a, Shape b) { 
		return a.vertexNum < b.vertexNum; 
	});
	
	printFigures(figures);
	
	return 0;
}

void printFigures(vector<Shape> shapes) {
	for_each(shapes.begin(), shapes.end(), [&](Shape shape) {
		cout << endl << "Vertex number: " << shape.vertexNum << endl;
		cout << "Points:" << endl;
		
		for_each(shape.vertexes.begin(), shape.vertexes.end(), [&](Point point) { cout << "x: " << point.x << ", y: " << point.y << endl; });
	});
}
