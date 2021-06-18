#include<iostream>
#include<string>
#include<map>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

/*
----------------------------------------------------
Associative containers: map, set, multimap, multiset
----------------------------------------------------
*/

#define MAP

void main()
{
	setlocale(LC_ALL, "");
#ifdef MAP
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0,"sunday"),
		std::pair<int, std::string>(1,"monday"),
		std::pair<int, std::string>(2,"tuesday"),
		std::pair<int, std::string>(3,"wednesday"),
		std::pair<int, std::string>(4,"thursday"),
		std::pair<int, std::string>(5,"friday"),
		std::pair<int, std::string>(6,"saturday"),
		std::pair<int, std::string>(3,"day")
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab << it->second << endl;
	}

	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::initializer_list<std::string>>("finite", {"ограниченный", "имеющий предел"}),
		std::pair<std::string, std::initializer_list<std::string>>("adjacent",{"примыкающий", "смежный", "соседний"}),
		std::pair<std::string, std::initializer_list<std::string>>("plot",{"карта", "план", "график", "сюжет"}),
		std::pair<std::string, std::initializer_list<std::string>>("incident",{"случайность", "проишествие"}),
		std::pair<std::string, std::initializer_list<std::string>>("splice",{"соединение", "сращивание", "соседний"}),
	};
	std::cout << dictionary["finite"].front() << std::endl;
	dictionary["space"].assign({ "пространство", "космос", " пробел" });
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		std::cout << it->first << ":";
		std::cout.width(20);
		
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			std::cout << *jt << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << dictionary.find("finite")->first << tab;
	for (std::string i : dictionary.find("finite")->second) std::cout << i << tab; std::cout << std::endl;
#endif // MAP






}