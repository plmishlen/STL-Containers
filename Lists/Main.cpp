#include<iostream>
#include<list>
#include<forward_list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";
#define delimeter "\n------------------------------------------------\n"

//#define LIST
//#define UNIQE
//#define LIST_MERGING
#define FORWARD_LIST

template<typename T>inline void list_properties(const std::list<T>& lst)
{
	cout << "Size: " << lst.size() << endl;
	cout << "Max_Size: " << lst.max_size() << endl;
}
template<typename T>void print_list(const std::list<T>& lst) 
{
	if (lst.empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

class list_wrapper
{
	std::list<int> lst;
};

void main()
{
	setlocale(LC_ALL,"");

#ifdef LIST
	std::list<int> lst = { 3,5,8,13,21 };
	cout << "Empty list size: " << sizeof(list_wrapper) << endl;
	list_properties(lst);
	print_list(lst);
	cout << endl;
	lst.push_front(2);
	lst.push_back(34);
	for (int i : lst)cout << i << tab; cout << endl;
	list_properties(lst);

	/*int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::list<int>::const_iterator position = lst.begin();
	for (int i = 0; i < index; i++)position++;
	lst.insert(position, value);
	print_list(lst);*/
	lst.resize(20);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		//cout << *it << tab;
		*it = rand() % 10;
	}
	cout << endl;

	for (std::list<int>::const_reverse_iterator it = lst.crbegin(); it != lst.crend(); it++)
		cout << *it << tab;
	cout << endl;
#endif // LIST
	
#ifdef UNIQE
	cout << delimeter << endl;
	lst.sort();
	for (int i : lst)cout << i << tab; cout << endl;
	cout << delimeter << endl;
	lst.unique();
	for (int i : lst)cout << i << tab; cout << endl;
	cout << delimeter << endl;
	lst.reverse();
	for (int i : lst)cout << i << tab; cout << endl;
	cout << delimeter << endl;
#endif // UNIQE

#ifdef LIST_MERGING
	std::list<int> lst1 = { 3,5,8,13,21 };
	std::list<int> lst2 = { 34,55,89 };
	//lst1.merge(lst2);
	lst2.merge(lst1);
	print_list(lst1);
	print_list(lst2);
#endif // LIST_MERGING

#ifdef FORWARD_LIST
	std::forward_list<int> flst = { 3,5,8,13,21 };
	flst.push_front(2);
	for (std::forward_list<int>::iterator it = flst.begin(); it != flst.end(); it++)
		cout << *it << tab;
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::forward_list<int>::iterator position = flst.before_begin();
	for (int i = 0; i < index; i++)position++;
	flst.insert_after(position, value);
	for (int i : flst)cout << i << tab; cout << endl;


#endif // FORWARD_LIST



}