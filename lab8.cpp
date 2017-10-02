/*
Kondrev Alexander
23531-21

Разработать программу, которая, используя только стандартные алгоритмы и
функторы, умножает каждый элемент списка чисел с плавающей точкой на число PI
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Functor {
	public:
		void operator() () {
			list<float> floats;
	
			cout << "Input random floats values" << endl;
			for (int i = 0; i < 10; i++) {
				float f;
				cin >> f;
				floats.push_back(f * 3.14);
			}
	
			for_each(floats.begin(), floats.end(), [&](float f) { cout << f << " "; });
		}
};

int main() {
	Functor functor;
	functor();
	return 0;
}
