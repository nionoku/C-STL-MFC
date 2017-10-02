/*
Kondrev Alexander
23531-21

Напишите программу – «телефонную книжку».
Записи (имя и телефон) должны хранится в каком-либо STL-контейнере (vector или
list), причем крайне желательно, чтобы от типа контейнера не зависело ничего, кроме
одной строки в программе – объявления этого контейнера (указание: используйте
typedef).
Программа должна поддерживать следующие операции:  Просмотр текущей записи
 Переход к следующей записи
 Переход к предыдущей записи
 Вставка записи перед/после просматриваемой  Замена просматриваемой записи  Вставка записи в конец базы данных
 Переход вперед/назад через n записей.
Помните, что после вставки элемента итераторы становятся недействительными,
поэтому после вставки целесообразно переставлять итератор на начало базы данных.
Постарайтесь реализовать операции вставки и замены с помощью одной и той же
функции, которой в зависимости от требуемого действия передается либо обычный
итератор, либо адаптер – один из итераторов вставки: void modifyRecord(iterator
pCurrentRecord, CRecord newRecord).
Программа может сразу после запуска сама (без команд пользователя) заполнить
записную книжку некоторым количеством записей.
*/

#include <iostream>
#include <list>
#include <string>

typedef struct Note;

using namespace std;

struct Note {
	string name;
	string number;
};

class Notepad {
	private:
		list<Note> notes;
		list<Note>::iterator notesIterator;
	
	public:
		// Конктруктор по умолчанию
	    Notepad() {
			notesIterator = notes.begin();
		}
		
		// Конструктор копирования
		Notepad(list<Note> &list) {
			notes.splice(notes.end(), list);
			notesIterator = notes.begin();
		}
		
		// метод возвращает текущую позицию в записной книжке
		Note currentNote() {
			if (notesIterator != notes.end())
				return *notesIterator;
		}
		
		// метод возвращает следующий элемент записной книжки
		Note nextNote() {
			notesIterator++;
			return currentNote();
		}
		
		// метод возвращает предыдущий элемент записной книжки
		Note previosNote() {
			notesIterator--;
			return currentNote();
		}
		
		Note nextNoteFrom(int count) {
			notesIterator = next(notesIterator, count);
			return currentNote();
		}
		
		// метод вставляет запись после текущего итератора
		void insertNote(Note &note) {
			notes.insert(notesIterator, note);
			notesIterator++;
		}
		
		// метод вставляет запись в конец бд
		void insertBack(Note &note) {
			notes.push_back(note);
		}
		
		// метод заменяет текущую запись
		void replaceCurrentNote(Note &note) {
			notes.erase(notesIterator);
			notes.insert(prev(notesIterator), note);
		}
};

int main() {
	Note note1;
	note1.name = "Alex";
	note1.number = "4545454";
	
	Notepad notepad;
	notepad.insertNote(note1);
	
	cout << notepad.currentNote().name << " " << notepad.currentNote().number << endl;
	return 0;
}
