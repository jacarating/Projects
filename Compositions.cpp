#include <iostream>
#include <cstring>


class Colour {
	char* colourName;
public:	Colour() {		colourName = nullptr;	}	

Colour(const char* str) {
		colourName = new char[strlen(str)+1];
		strcpy(colourName, str);
	}


	~Colour() { delete[] colourName; }

	void display() const { std::cout << colourName << std::endl;	}


	void Set(const char* newColour) {
		delete[] colourName;
		colourName = new char[strlen(newColour)+1];
		strcpy(colourName, newColour);
	}
};


class Car {
	Colour subObject;
	char* name;
	int year;
public:	Car() {

		name = nullptr;

		year = 0;	}	

Car(const char* str, int recYear, const char* recCol) {

		name = new char[strlen(str)+1];

		strcpy(name, str);
		subObject.Set(recCol);
		year = recYear;
	}


	void SetColour(const char* newColour) {
		subObject.Set(newColour);
	}


	void display() {		std::cout << name << ' ' << year << ' ';		subObject.display();	}
	

~Car() { delete[] name; }
};

int main() {
	Car test("Mazda", 2014, "Black");
	test.display();	

return 0;

}
