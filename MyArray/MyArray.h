#pragma once
#include <iostream>
using namespace std;

template<class T = int>
class MyArray
{
	T* arr;
	int size;
	int capacity;
public:
	MyArray();                                      //конструктор по умолчанию
	MyArray(int s);                                 //конструктор с параметрами
	MyArray(const MyArray& obj);                    //конструктор копирования
	~MyArray();                                     //декструктор
	void Print();                                   //вывод массива
	void Random();                                  //заполнить массив
	int GetSize();                                  //вернуть количество заполненного массива
	void SetSize(int s, int grow);                  //установка размера массива
	int GetUpperBound();                            //индекс последнего элемента
	bool IsEmpty();                                 //проверка на пустоту массива
	void FreeExtra();                               //удалить лишнюю выделенную памать под массив
	void RemoveAll();                               //удалить всё
	int operator[](int index);                      //возвращение элемента массива по индексу
	int* GetAt();                                   //получение элемента массива по индексу
	void SetAt(int index, int val_2);               //изменение значения и возвращение элемента массива по индексу
	void Add(int val);                              //добавление элемента в массив
	void Append(MyArray arr);                       //добавление массива к массиву
	MyArray& operator=(const MyArray& obj);         //оператор присваивания
	T* GetData();                                   //получение адреса массива
	void InsertAt(MyArray arr, int index);          //добавление элементов в массив
	void RemoveAt(int index_start, int index_end);  //удаление элементов из массива
};

//конструктор по умолчанию
template<class T>
MyArray<T>::MyArray() {
	arr = nullptr;
	size = 0;
	capacity = 0;
}

//конструктор с параметрами
template<class T>
MyArray<T>::MyArray(int s) {
	capacity = size = s;
	arr = new T[s];
}

//конструктор копирования
template<class T>
MyArray<T>::MyArray(const MyArray& obj) {
	size = obj.size;
	capacity = obj.capacity;

	arr = new T[capacity];
	for (int i = 0; i < size; i++) {
		arr[i] = obj.arr[i];
	}
}

//декструктор
template<class T>
MyArray<T>::~MyArray() {
	delete[] arr;
	size = 0;
	capacity = 0;
}

//вывод массива
template<class T>
void MyArray<T>::Print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl << endl;
}

//заполнить массив
template<class T>
void MyArray<T>::Random() {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 * 1.6;
	}
}

//вернуть количество заполненного массива
template<class T>
int MyArray<T>::GetSize() {
	return size;
}

//установка размера массива
template<class T>
void MyArray<T>::SetSize(int s, int grow) {
	if (s > size) {
		if (s > capacity)
			capacity += grow;
		size = s;		
	}
	else if (s < size) {
		size = s;
	}
}

//индекс последнего элемента
template<class T>
int MyArray<T>::GetUpperBound() {
	return size - 1;
}

//проверка на пустоту массива
template<class T>
bool MyArray<T>::IsEmpty() {
	if (size = 0) {
		return true;
	}
	else return false;
}

//удалить лишнюю выделенную памать под массив
template<class T>
void MyArray<T>::FreeExtra() {
	if (size < capacity) {
		capacity = capacity - size;
	}
}

//удалить всё
template<class T>
void MyArray<T>::RemoveAll() {
	size = 0;
	capacity = 0;
}

//возвращение элемента массива по индексу
template<class T>
int MyArray<T>::operator[](int index) {
	return arr[index];
}

//получение элемента массива по индексу
template<class T>
int* MyArray<T>::GetAt() {
	return arr;
}

//изменение значения и возвращение элемента массива по индексу
template<class T>
void MyArray<T>::SetAt(int index, int val_2) {
	arr[index] = val_2;
}

//добавление элемента в массив
template<class T>
void MyArray<T>::Add(int val) {
	SetSize(size + 1, 1);
	arr[size - 1] = val;
}

//добавление массива к массиву
template<class T>
void MyArray<T>::Append(MyArray arr) {
	int new_s = size + arr.size;
	SetSize(new_s, arr.size);

	for (int i = size - arr.size, k = 0; i < size ; i++, k++) {
		this->arr[i] = arr.arr[k];
	}
}

//оператор присваивания
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& obj) {
	if (this == &obj) {
		return *this;
	}
	if (arr != nullptr) {
		this->~MyArray();
	}
	size = obj.size;
	capacity = obj.capacity;

	arr = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = obj.arr[i];
	}
	return *this;
}

//получение адреса массива
template<class T>
T* MyArray<T>::GetData() {
	return arr;
}

//добавление элементов в массив
template<class T>
void MyArray<T>::InsertAt(MyArray arr, int index) {
	MyArray<int> obj(*this->arr);
	for (int i = 0; i < size; i++)
		obj.arr[i] = this->arr[i];

	int new_s = size + arr.size;
	SetSize(new_s, arr.size);
	
	for (int i = index + arr.size, k = index; i < size; i++, k++) {
		this->arr[i] = obj.arr[k];
	}
	for (int i = index, k = 0; i <= arr.size + 1; i++, k++) {
		this->arr[i] = arr[k];
	}
}

//удаление элементов из массива
template<class T>
void MyArray<T>::RemoveAt(int index_start, int index_end) {
	MyArray<int> obj(*this->arr);
	for (int i = 0; i < size; i++)
		obj.arr[i] = this->arr[i];

	for (int i = index_start, k = index_end + 1; i <= index_end; i++, k++) {
		arr[i] = obj.arr[k];
	}
	int new_s = size - (index_end - index_start + 1);
	SetSize(new_s, index_end);
}