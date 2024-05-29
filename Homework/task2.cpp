#include <iostream>
using namespace std;

class Reservoir {
private:
	char* name;
	int width;  
	int length; 
	int depth;
	char* type;
public:
	Reservoir() : width(0), length(0), depth(0) {
		name = new char[1];
		name[0] = '\0';
		type = new char[1];
		type[0] = '\0';
	}
	Reservoir(const char* name, double width, double length, double depth, const char* type) : width(width), length(length), depth(depth) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
	Reservoir(const Reservoir& other) : width(other.width), length(other.length), depth(other.depth) {
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		type = new char[strlen(other.type) + 1];
		strcpy_s(type, strlen(other.type) + 1, other.type);
	}
	Reservoir& operator=(const Reservoir& other) {
		if (this != &other) {
			delete[] name;
			delete[] type;
			width = other.width;
			length = other.length;
			depth = other.depth;
			name = new char[strlen(other.name) + 1];
			strcpy_s(name, strlen(other.name) + 1, other.name);
			type = new char[strlen(other.type) + 1];
			strcpy_s(type, strlen(other.type) + 1, other.type);
		}
		return *this;
	}
	~Reservoir() {
		delete[] name;
		delete[] type;
	}
	double calculateVolume() const {
		return width * length * depth;
	}

	double calculateSurfaceArea() const {
		return width * length;
	}

	void isSameType(const Reservoir& other) {
		if (strcmp(type, other.type) == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	void isLargerSurfaceArea(const Reservoir& other) {
		if (strcmp(type, other.type) == 0) {
			cout << "Surface Area " << name << ": " << calculateSurfaceArea() << endl;
			cout << "Surface Area " << other.name << ": " << other.calculateSurfaceArea() << endl;
			if (calculateSurfaceArea() > other.calculateSurfaceArea()) {
				cout << name << " > " << other.name << endl;
			}
			else {
				cout << name << " < " << other.name << endl;
			}
		}
		else {
			cout << "Reservoirs are not suitable" << endl;
		}
	}
	void Output() {
		cout << "Name: " << name << "\nType: " << type
			<< "\nWidth: " << width << "\nLength: " << length
			<< "\nMax Depth: " << depth << "\nVolume: "
			<< calculateVolume() << "\nSurface Area: "
			<< calculateSurfaceArea() << endl;
	}
};

void addReservoir(Reservoir*& reservoirs, int& size, const Reservoir& newReservoir) {
	Reservoir* temp = new Reservoir[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = reservoirs[i];
	}
	temp[size] = newReservoir;
	delete[] reservoirs;
	reservoirs = temp;
	size++;
}
void deleteReservoir(Reservoir*& reservoirs, int& size, int index) {
	if (index < 0 || index >= size) {
		cout << "Invalid index" << endl;
		return;
	}
	Reservoir* temp = new Reservoir[size - 1];
	for (int i = 0, j = 0; i < size; i++) {
		if (i != index) {
			temp[j++] = reservoirs[i];
		}
	}
	delete[] reservoirs;
	reservoirs = temp;
	size--;
}

void prosto() {
	cout << "----------------------------------" << endl;
}

//int main() {
//	int size = 0;
//	Reservoir* reservoirs = nullptr;
//
//	addReservoir(reservoirs, size, Reservoir("Black Sea", 10, 20, 42, "Sea"));
//
//	for(int i = 0; i < size; i++) {
//		reservoirs[i].Output();
//		cout << endl;
//	}
//
//	prosto();
//
//	addReservoir(reservoirs, size, Reservoir("White Sea", 20, 70, 12, "Sea")); 
//	addReservoir(reservoirs, size, Reservoir("Lake lake", 2, 3, 4, "Lake"));
//
//	for (int i = 0; i < size; i++) {
//		reservoirs[i].Output();
//		cout << endl;
//	}
//	
//	prosto();
//
//	deleteReservoir(reservoirs, size, 2);
//
//	for (int i = 0; i < size; i++) {
//		reservoirs[i].Output();
//		cout << endl;
//	}
//
//	prosto();
//
//	reservoirs[0].isSameType(reservoirs[1]);
//
//	reservoirs[0].isLargerSurfaceArea(reservoirs[1]);
//
//	delete[] reservoirs;
//}