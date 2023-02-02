#include <iostream>
#include <vector>

class IVehicle {
public:
	virtual void printName() const = 0;
	virtual ~IVehicle() {}
};

class Car : public IVehicle {
public:
	void printName() const override {
		std::cout << "Car class" << std::endl;
	}
};

void foo(std::vector<IVehicle*>& vec) {	// я убрал константы, можно пробросить и константные, но тогда надо обозначить,что вектор будет константным, состоящий из константных указателей класса IVehicle
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i]->printName();
	}
}

int main() {
	/*IVehicle* vehicle = new IVehicle();*/	// мы не можем создавать объекты абстрактного класса
	IVehicle* vehicle2 = new Car();	// Из того, что есть, можем создать только new Car()
	std::vector<IVehicle*> vec { vehicle2 };	
	foo(vec);	// Пробрасываемые значения отличаются от тех, которые находятся в параметрах функции

}