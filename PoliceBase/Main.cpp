#include<iostream>
#include<string>
#include<map>
#include<list>
#include<forward_list>
#include<windows.h>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------------------------------------------\n"

int menu(std::map<std::string, std::forward_list<std::string>>& base);
void print_base(const std::map<std::string, std::forward_list<std::string>>& base);
void add_crime(std::map < std::string, std::forward_list<std::string>>& base);
void crimes_of(std::string id, const std::map < std::string, std::forward_list<std::string>>& base);


void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*system("CHCP 1251");
	system("CLS");*/
	std::map<std::string, std::forward_list<std::string>> base =
	{
		std::pair<std::string, std::forward_list<std::string>>("�123��777", {"������ �� ������� ����", "���������� ��������"}),
		std::pair<std::string, std::forward_list<std::string>>("�124��777", {"�������� � ������������ �����"}),
		std::pair<std::string, std::forward_list<std::string>>("�555��777", {"���������� ��������"}),
		std::pair<std::string, std::forward_list<std::string>>("�123��777", {"������ �� ������� ����", "���������� ��������"}),
		std::pair<std::string, std::forward_list<std::string>>("�123��178", {"������ �� ������� ����", "����������� ��������"})
	};
	/*print_base(base);
	add_crime(base);
	print_base(base);*/
	/*std::string id;
	cout << "������� ����� ����: "; cin >> id;
	crimes_of(id, base);*/
	menu(base);
}

int menu(std::map<std::string, std::forward_list<std::string>>& base)
{
	cout << "1. ����� ���� ����: " << endl;
	cout << "2. ����� ���������� �� ������: " << endl;
	cout << "3. ����� �� ��������� �������: " << endl;
	cout << "4. ���������� ���������: " << endl;
	cout << "5. �����; " << endl;
	int choice;
	cin >> choice;
	std::string id;
	switch (choice)
	{
	case1: print_base(base); break;
	case2:
		cout << "������� ����� ������: "; cin >> id;
		crimes_of(id, base);
		break;

	case4:add_crime(base); break;
	case5:return choice;
	default:cout << "������������ ��������: " << endl;
	}
	menu(base);
	return choice;
}

void print_base(const std::map<std::string, std::forward_list<std::string>>& base)
{
	for (std::map<std::string, std::forward_list<std::string>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ": \t";
		for (std::forward_list<std::string>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << *l_it << ", ";
		}
		cout << "\b \b";
		cout << "\b \b";
		cout << ";";
		cout << delimeter;
	}
}

void add_crime(std::map < std::string, std::forward_list<std::string>>& base)
{
	std::string id, cr;
	cout << "������� ����� ����������: "; cin >> id;
	cout << "������� ��������������: "; 
	cin.ignore();
	getline(cin, cr);
	base[id].push_front(cr);
}

void crimes_of(std::string id, const std::map < std::string, std::forward_list<std::string>>& base)
{
	std::map<std::string, std::forward_list<std::string>>::const_iterator criminal = base.find(id);
	if (base.find(id) != base.end())
	{
		cout << "������ ��������� " << id << ":\n";
		for (std::forward_list<std::string>::const_iterator it = criminal->second.begin(); it != criminal->second.end(); it++)
		{
			cout << *it << endl;
		}
	}
}


