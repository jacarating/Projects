// TODO: Write (practice) program by using template class, template function, specialization, default parameter, variadic templates, function pointer, trailing return type declarations....


#include <iostream>
// Template Class:
template<typename T = int> // Default Parameter
class List {
	T value;

public:
	List() : value{} {};

	List(T argc = 0) {
		value = argc;
	}

	// Template Functions: 
	T add(T src) {
		return value += src;
	}

	T remove(T src) {
		return value -= src;
	}

	// Variadic Template Functions: 
	template<typename T, typename ... Argcs>
	T add(T a, Argcs ...b) {
		return value = ( a + add(b...));
	}

	template<typename T, typename ... Argcs>
	T remove(T a, Argcs ...b) {
		return value - (remove(a) + remove(b...));
	}

	T getValue() const {
		return value;
	}

	// Template Specialization: 
	template<>
	double add<double>(double a, double b, double c) {
		return value = 99999;
	}
	
};



// Trailing Return Type:
template<typename T1, typename T2>
auto sum(T1 & t1, T2 & t2) -> decltype(t1.getValue() + t2.getValue()) {

	return t1.getValue() + t2.getValue();

}

int add10() { return 10; }

int main() {
	List<> test2(10);
	List<double> test3(2);
	List<double> test4(5.3);
	

	int(*funPtr)() = add10;

	test2.add(5, 5);
	test2.remove(8);
	test2.add(funPtr()); // Adds ten to value using a Function Pointer.
	std::cout << test2.getValue() << std::endl; 

	test3.add(3.5, 4.57);

	std::cout << test3.getValue() << std::endl; 

	auto result = sum(test2, test3);

	std::cout << result << std::endl;

	
	test4.add(3.4, 23.1, 1.4);
	std::cout << test4.getValue() << std::endl;



	return 0;
}
