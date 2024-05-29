#include <iostream>
using namespace std;

class String {
private:
	char* str;
	int size;
public:
	String() : String(80) {}
	String(int size) : size(size) {
		str = new char[size + 1];
		str[0] = '\0';
	}
	String(const String& other) : size(other.size) {
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = other.str[i];
		}
		str[size] = '\0';
	}
	String(const char* inputStr) {
		size = 0;
		while (inputStr[size] != '\0') {
			size++;
		}
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = inputStr[i];
		}
		str[size] = '\0';
	}
	~String() {
		delete[] str;
	}
	void input() {
		char InputP[1000];
		cout << "Enter your text: ";
		gets_s(InputP);
		int size_i = 0;
		while (InputP[size_i] != '\0') {
			size_i++;
		}
		size = size_i;
		delete[] str;
		str = new char[size + 1];
		for (int i = 0; i < size; i++) {
			str[i] = InputP[i];
		}
		str[size] = '\0';
	}
	void Output() {
		cout << str << endl;
	}
};

int main() {
	String str1;
	str1.input();
	str1.Output();
}