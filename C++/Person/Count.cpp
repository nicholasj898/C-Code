#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;

//prototypes
int lengthOfName(Person	*p);

int main()
{
	int peopleCount;
	int age;
	string name;
	cout << "Please enter number of people: ";
	cin >> peopleCount;
	vector<Person> people(peopleCount);
	for (int index = 0; index < peopleCount; index++)
	{
		cout << "Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
		people[index].setName(name);
		people[index].setAge(age);
	}
	cout << "YOU HAVE " << people.size() << " people" << endl;

	/* seems redundant to declare Person, but the spec. called for it */
	vector<Person>::iterator it;
	for (it = people.begin(); it != people.end(); ++it) {
		Person *pPerson = new Person(it->getName(), it->getAge());
		cout << "The name " << pPerson->getName() 
			<< " (age: " << pPerson->getAge() << ") has as a length of " 
			<< lengthOfName(pPerson) << endl;
	}
	return 0;
}

//******************************************************
//   Returns the number of characters in a person's name
//******************************************************
int lengthOfName(Person *p)
{
	string name = p->getName();
	return name.length();
}
