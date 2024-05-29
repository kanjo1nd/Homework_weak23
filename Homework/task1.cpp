#include <iostream>
using namespace std;

class Human {
private:
	char* name;
public:
	Human() : name(nullptr) {}
	Human(const char* Name) {
		this->name = new char[strlen(Name) + 1];
		strcpy_s(this->name, strlen(Name) + 1, Name);
	}
	Human(const Human& obj) {
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
	}
	Human& operator=(const Human& other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy_s(name, strlen(other.name) + 1, other.name);
		}
		return *this;
	}
	~Human() {
		delete[] name;
	}
	void Output() {
		cout << "Name: " << name << endl;
	}
};

class Apartment {
private:
	Human* people;
	int peopleCount;
public:
	Apartment(int peopleCount = 0) : peopleCount(peopleCount) {
		if (peopleCount > 0) {
			people = new Human[peopleCount];
		}
		else {
			people = nullptr;
		}
	}
	Apartment(const Apartment& obj) : peopleCount(obj.peopleCount) {
		people = new Human[peopleCount];
		for (int i = 0; i < peopleCount; i++) {
			people[i] = obj.people[i];
		}
	}
	~Apartment() {
		delete[] people;
	}
	Apartment& operator=(const Apartment& other) {
		if (this != &other) {
			delete[] people;
			peopleCount = other.peopleCount;
			if (peopleCount > 0) {
				people = new Human[peopleCount];
				for (int i = 0; i < peopleCount; i++) {
					people[i] = other.people[i];
				}
			}
			else {
				people = nullptr;
			}
		}
		return *this;
	}
	void AddHuman(const Human& person) {
		Human* newPeople = new Human[peopleCount + 1];
		for (int i = 0; i < peopleCount; i++) {
			newPeople[i] = people[i];
		}
		newPeople[peopleCount] = person;
		delete[] people;
		people = newPeople;
		peopleCount++;
	}
	void Output() {
		cout << "Apartment with " << peopleCount << " people:" << endl;
		for (int i = 0; i < peopleCount; i++) {
			people[i].Output();
		}
	}
};

class Home {
private:
	Apartment* apartments;
	int apartmentCount;
public:
	Home(int apartmentCount = 0) : apartmentCount(apartmentCount) {
		apartments = new Apartment[apartmentCount];
	}

	Home(const Home& other) : apartmentCount(other.apartmentCount) {
		apartments = new Apartment[apartmentCount];
		for (int i = 0; i < apartmentCount; i++) {
			apartments[i] = other.apartments[i];
		}
	}
	~Home() {
		delete[] apartments;
	}
	Home& operator=(const Home& other) {
		if (this != &other) {
			delete[] apartments;
			apartmentCount = other.apartmentCount;
			if (apartmentCount > 0) {
				apartments = new Apartment[apartmentCount];
				for (int i = 0; i < apartmentCount; i++) {
					apartments[i] = other.apartments[i];
				}
			}
			else {
				apartments = nullptr;
			}
		}
		return *this;
	}
	void addApartment(const Apartment& apartment) {
		Apartment* newApartments = new Apartment[apartmentCount + 1];
		for (int i = 0; i < apartmentCount; i++) {
			newApartments[i] = apartments[i];
		}
		newApartments[apartmentCount] = apartment;
		delete[] apartments;
		apartments = newApartments;
		++apartmentCount;
	}

	void Output() {
		cout << "House with " << apartmentCount << " apartments:" << endl;
		for (int i = 0; i < apartmentCount; i++) {
			apartments[i].Output();
		}
	}
};

//int main() {
//	Home home;
//	Apartment apartment1;
//	Human person1("Stepan");
//	apartment1.AddHuman(person1);
//	home.addApartment(apartment1);
//
//	Apartment apartment2;
//	Human person2("Ivan");
//	Human person3("Igor");
//	apartment2.AddHuman(person2);
//	apartment2.AddHuman(person3);
//	home.addApartment(apartment2);
//
//	home.Output();
//}