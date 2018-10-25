// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 2 - Problem 2
// Program: CS213-2018-A2-T2-P2
// Purpose: Creating a class Pet with 3 subclasses and printing their descriptions
// Author1: Mostafa Omar Mahmoud - 20170292
// Date:    25 October 2018
// Version: 1.0

#include <iostream>
using namespace std;
class Pet{
public:
	string name;
	bool neuterSpayed;
	bool talks;
	Pet()
	{
		neuterSpayed = 0;
		talks = 0;
	}
	void setTalks(bool b)
	{
		talks = b;
	}
	void setName(string s)
	{
		name = s;
	}
	void setNeuterSpayed(bool b)
	{
		neuterSpayed = b;
	}
	virtual void printDescription()
	{
		cout << "Pet named " << name << '\n';
		cout << "Neuter/Spayed " << neuterSpayed << '\n';
	}
	virtual ~Pet(){};

};

class Dog:public Pet{
public:
	Dog(){
	}
	virtual void printDescription()
	{
		cout << "Dog named " << name << '\n';
		cout << "Neuter/Spayed: " << neuterSpayed << '\n';
	}
	virtual ~Dog(){};
};

class Cat:public Pet
{
public:
	Cat()
	{
	}
	virtual void printDescription()
	{
		cout << "Cat named " << name << '\n';
		cout << "Neuter/Spayed: " << neuterSpayed << '\n';
	}
	virtual ~Cat(){};
};

class Bird:public Pet
{
public:
	Bird()
	{
	}
	virtual void printDescription()
	{
		cout << "Bird named " << name << '\n';
		cout << "Neuter/Spayed: " << neuterSpayed << '\n';
		cout << "Talks: " << talks << '\n';
	}
	virtual ~Bird(){};
};
int main() {
	// Testing virtual functions
	Pet** arr = new Pet*[3];

	// First subclass: Dog
	arr[0] = new Dog;
	string name;
	cout << "Enter dog name: ";
	cin >> name;
	arr[0]->setName(name);
	bool b;
	cout << "Is the dog Neuter/Spayed? (0/1): ";
	cin >> b;
	arr[0]->setNeuterSpayed(b);

	//Second subclass: cat
	arr[1] = new Cat;
	cout << "Enter cat name: ";
	cin >> name;
	arr[1]->setName(name);
	cout << "Is the cat Neuter/Spayed? (0/1): ";
	cin >> b;
	arr[1]->setNeuterSpayed(b);

	//Third subclass: Bird
	arr[2] = new Bird;
	cout << "Enter bird name: ";
	cin >> name;
	arr[2]->setName(name);
	cout << "Is the bird Neuter/Spayed? (0/1): ";
	cin >> b;
	arr[2]->setNeuterSpayed(b);
	cout << "Does the bird talk? (0/1): ";
	cin >> b;
	arr[2]->setTalks(b);

	cout << '\n';
	for (int i = 0; i < 3; ++i)
	{
		arr[i]->printDescription();
		cout << '\n';
	}
	return 0;
}
