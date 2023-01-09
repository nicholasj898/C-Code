#pragma once
#include <string>
using namespace std;
class Person
{
private:
	int age;
	string name;

public:
	Person();

	Person(string initName, int initAge)
	{
		name = initName;
		age = initAge;
	}

	~Person();

	void setAge(int age1)
	{
		age = age1;
		return;
	}

	void setName(string name1)
	{
		name = name1;
		return;
	}

	int getAge()
	{
		return age;
	}

	string getName() 
	{
		return name;
	}
};