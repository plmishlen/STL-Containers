#include<iostream>
#include<array>
#include<vector>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


#define tab "\t"
#define delimeter "\n------------------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_VECTOR_INSERT
//#define VECTOR_SWAP
#define STL_VECTOR_ERASE

template<typename T>void vector_properties(const vector<T>& vec);
template<typename T>void print_vector(const vector<T>& vec);
template<typename T>void reverse_print_vector(const vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << tab;
		cout << arr.at(i) << tab;
	}
	cout << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *arr.data() << endl;

	arr.fill(123);
	for (int i : arr)
		cout << i << tab;
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	vec.push_back(55);
	/*cout <<"Size: "<< vec.size() << endl;
	cout <<"Capacity: "<< vec.capacity() << endl;
	cout <<"Max size: " << vec.max_size() << endl;*/
	vector_properties(vec);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	vec.reserve(45);
	//vec.shrink_to_fit();
	vector_properties(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << delimeter << endl;
	vec.assign({ 1024,2048,3072 });
	print_vector(vec);
	vector_properties(vec);

#endif // STL_VECTOR

#ifdef STL_VECTOR_INSERT
	int index;
	int count;
	int value;
	do
	{
		cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
		if (index > vec.size())cout << "error\n";
	} 	while (index > vec.size());
	cout << "¬ведите количество добавл€емых элементов: "; cin >> count;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	//vec.insert(position, count, value);
	vec.insert(vec.begin()+index, count, value);
	for (int i : vec)
	{
		cout << i << tab;
	}
	cout << endl;
	vector_properties(vec);


	vec.insert(vec.begin() + 8, vec.begin() + 3, vec.begin() + 8);
	for (int i : vec) cout << i << tab;
	cout << endl;
#endif // STL_VECTOR_INSERT

	/*cout << delimeter << endl;
	vec.insert(vec.begin() + 5, {1024, 2048, 3072,4096});
	print_vector(vec);
	vector_properties(vec);
	cout << "Ётот вектор занимает: " << sizeof(vec) << " байт " << endl;
	cout << delimeter << endl;
	vector<int> vec2;
	cout << "ѕустой вектор занимает: " << sizeof(vec2) << " байт " << endl;*/

#ifdef VECTOR_SWAP
	vector<int> vec1 = { 3, 5, 8, 13, 21 };
	vector<int> vec2 = { 34,55,89 };
	print_vector(vec1);
	print_vector(vec2);
	vec1.swap(vec2);
	print_vector(vec1);
	print_vector(vec2);
#endif // VECTOR_SWAP

#ifdef STL_VECTOR_ERASE
	vector <int>vec = { 3,5,8,13,21,34,55 };
	print_vector(vec);
	/*int index;
	cout << "¬ведите индекс удал€емого элемента: "; cin >> index;
	vector<int>::iterator position = vec.begin() + index;
	vec.erase(position);		//vec.erase(vec.begin() + index);*/
	int index_start, index_end;
	cout << "¬ведите начало удал€емого диапазона: "; cin >> index_start;
	cout << "¬ведите конец удал€емого диапазона: "; cin >> index_end;
	vec.erase(vec.begin() + index_start, vec.begin() + index_end);
	print_vector(vec);
	vector_properties(vec);
	reverse_print_vector(vec);
#endif STL_VECTOR_ERASE
	


}
template<typename T>void vector_properties(const vector<T>& vec)
{
	cout << "Size: " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;
}
template<typename T>void print_vector(const vector<T>& vec)
{
	for (int i : vec)cout << i << tab; cout << endl;
}
template<typename T>void reverse_print_vector(const vector<T>& vec)
{
	for(vector<int>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); it++)
		cout << *it << tab;
	cout << endl;
}