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
	MyArray();                                      //����������� �� ���������
	MyArray(int s);                                 //����������� � �����������
	MyArray(const MyArray& obj);                    //����������� �����������
	~MyArray();                                     //�����������
	void Print();                                   //����� �������
	void Random();                                  //��������� ������
	int GetSize();                                  //������� ���������� ������������ �������
	void SetSize(int s, int grow);                  //��������� ������� �������
	int GetUpperBound();                            //������ ���������� ��������
	bool IsEmpty();                                 //�������� �� ������� �������
	void FreeExtra();                               //������� ������ ���������� ������ ��� ������
	void RemoveAll();                               //������� ��
	int operator[](int index);                      //����������� �������� ������� �� �������
	int* GetAt();                                   //��������� �������� ������� �� �������
	void SetAt(int index, int val_2);               //��������� �������� � ����������� �������� ������� �� �������
	void Add(int val);                              //���������� �������� � ������
	void Append(MyArray arr);                       //���������� ������� � �������
	MyArray& operator=(const MyArray& obj);         //�������� ������������
	T* GetData();                                   //��������� ������ �������
	void InsertAt(MyArray arr, int index);          //���������� ��������� � ������
	void RemoveAt(int index_start, int index_end);  //�������� ��������� �� �������
};

//����������� �� ���������
template<class T>
MyArray<T>::MyArray() {
	arr = nullptr;
	size = 0;
	capacity = 0;
}

//����������� � �����������
template<class T>
MyArray<T>::MyArray(int s) {
	capacity = size = s;
	arr = new T[s];
}

//����������� �����������
template<class T>
MyArray<T>::MyArray(const MyArray& obj) {
	size = obj.size;
	capacity = obj.capacity;

	arr = new T[capacity];
	for (int i = 0; i < size; i++) {
		arr[i] = obj.arr[i];
	}
}

//�����������
template<class T>
MyArray<T>::~MyArray() {
	delete[] arr;
	size = 0;
	capacity = 0;
}

//����� �������
template<class T>
void MyArray<T>::Print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl << endl;
}

//��������� ������
template<class T>
void MyArray<T>::Random() {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 * 1.6;
	}
}

//������� ���������� ������������ �������
template<class T>
int MyArray<T>::GetSize() {
	return size;
}

//��������� ������� �������
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

//������ ���������� ��������
template<class T>
int MyArray<T>::GetUpperBound() {
	return size - 1;
}

//�������� �� ������� �������
template<class T>
bool MyArray<T>::IsEmpty() {
	if (size = 0) {
		return true;
	}
	else return false;
}

//������� ������ ���������� ������ ��� ������
template<class T>
void MyArray<T>::FreeExtra() {
	if (size < capacity) {
		capacity = capacity - size;
	}
}

//������� ��
template<class T>
void MyArray<T>::RemoveAll() {
	size = 0;
	capacity = 0;
}

//����������� �������� ������� �� �������
template<class T>
int MyArray<T>::operator[](int index) {
	return arr[index];
}

//��������� �������� ������� �� �������
template<class T>
int* MyArray<T>::GetAt() {
	return arr;
}

//��������� �������� � ����������� �������� ������� �� �������
template<class T>
void MyArray<T>::SetAt(int index, int val_2) {
	arr[index] = val_2;
}

//���������� �������� � ������
template<class T>
void MyArray<T>::Add(int val) {
	SetSize(size + 1, 1);
	arr[size - 1] = val;
}

//���������� ������� � �������
template<class T>
void MyArray<T>::Append(MyArray arr) {
	int new_s = size + arr.size;
	SetSize(new_s, arr.size);

	for (int i = size - arr.size, k = 0; i < size ; i++, k++) {
		this->arr[i] = arr.arr[k];
	}
}

//�������� ������������
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

//��������� ������ �������
template<class T>
T* MyArray<T>::GetData() {
	return arr;
}

//���������� ��������� � ������
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

//�������� ��������� �� �������
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