#include <iostream>
#include<map>
#include <set>
#include <list>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------------------------------------------\n"
#define tab "\t"

class MyInt;

//#define STL_MAP_1
//#define STL_SET
#define STL_MAP_2
//#define GAI
class MyInt
{
	int value;
public:
	MyInt(int value = 0) :value(value) {}
	~MyInt() {}
	bool operator<(const MyInt& other)const
	{
		return this->value < other.value;
	}
	friend std::ostream& operator<<(std::ostream& os, const MyInt& obj)
	{
		return os << obj.value;
	}
};

void append_offense(std::map<std::string, std::list<std::string>> offense_list, std::pair<std::string, std::string> offense_pair)
{
	for (std::pair<std::string, std::list<std::string>> i : offense_list)
	{
		if (offense_pair.first == i.first) 
		{
			i.second.push_back(offense_pair.second);
			return;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_MAP_1
	std::multimap<int, std::string> weekdays =
	{
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(6, "Saturday"),
		std::pair<int, std::string>(7, "Sunday"),
	};
	
	/*for (std::multimap<int, std::string>::iterator it = weekdays.begin(); it != weekdays.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}*/

	for (std::pair<int, std::string> i : weekdays)
	{
		cout << i.first << "\t" << i.second << endl;
	}
	cout<<endl;



#endif // STL_MAP

#ifdef STL_SET
	std::set<int> i_set = { 50, 25,75,16,32,58,85 };
	for (std::set<int>::iterator it = i_set.begin(); it != i_set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (int i : i_set)
	{
		cout << i << tab;
	}
	cout<<endl;
	MyInt a = 5;
	cout << a << endl;

	std::set<MyInt> my_set = { 50,25,75,16,32,58,85 };
	for (std::set<MyInt>::iterator it = my_set.begin(); it != my_set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (MyInt i : my_set)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP_2

	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("statement", {"заявление", "утверждение", "формулировка"}),
		{"space",{"космос","пространство", "пробел"}},
		{"promise", {"обещание", "проекция", "перспектива"}},
		{"accept",{"принимать","брать","опускать","соглашаться","признавать","соглашаться"}},
		{"reverse",{"переворачивать","перевернутый","обратный"}}
	};
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << "\t";
		for (std::list<std::string>::iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
			cout << *l_it << tab;
		cout << endl;
	}
	cout << delimiter << endl;
	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		cout << i.first << "\t";
		for (std::string j : i.second)
		{
			cout << j << ",";
		}
		cout << endl;
	}
	cout << endl;
#endif // STL_MAP_2

#ifdef GAI
	std::map<std::string, std::list<std::string>> offense_list;
	std::pair<std::string, std::string> offense("H666EZ","Превышение скорости");
	append_offense(offense_list, offense);
	for (std::pair<std::string, std::list<std::string>> i : offense_list)
	{
		cout << i.first << "\t";
		for (std::list<std::string>::iterator l_it = i.second.begin(); l_it != i.second.end(); ++l_it)
			cout << *l_it << tab;
	}
	cout << endl;
#endif // GAI

	 
}

