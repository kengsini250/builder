#include <iostream>
using namespace std;

class Name
{
private:
	string name = "";

public:
	void set(string s)
	{
		name = s;
	}
	string get()
	{
		return name;
	}
};

class Value
{
private:
	int value = 0;
	int RMB = 0;
	int JPY = 0;

public:
	void set(int s)
	{
		value = s;
	}
	void setRMB(int r)
	{
		RMB = r;
	}
	void setJPY(int j)
	{
		JPY = j;
	}
	int get()
	{
		return value;
	}
	int getRMB()
	{
		return RMB;
	}
	int getJPY()
	{
		return JPY;
	}
};

class Size
{
private:
	string size = "";
	int capacity = 0;

public:
	void set(string s)
	{
		size = s;
	}
	void setCapacity(int i)
	{
		capacity = i;
	}
	string get()
	{
		return size;
	}
	int getCapacity()
	{
		return capacity;
	}
};

class Food
{
private:
	Name *name;
	Value *value;
	Size *size;

public:
	void setName(Name *n)
	{
		name = n;
	}
	void setValue(Value *v)
	{
		value = v;
	}
	void setSize(Size *s)
	{
		size = s;
	}

	Name* getName()
	{
		return name;
	}
	Value *getValue()
	{
		return value;
	}
	Size* getSize()
	{
		return size;
	}

	void print()
	{
		std::cout << "name : " << name->get() << "\n";

		if(value->get() != 0)
			std::cout << "value : " << value->get() << "$\n";
		if(value->getRMB() != 0)
			std::cout << "RMB : " << value->getRMB() << "RMB\n";
		if(value->getJPY() != 0)
			std::cout << "JPY : " << value->getJPY() << "JPY\n";

		if(size->get() != "")
			std::cout << "size : " << size->get() << "\n";
		if(size->getCapacity() != 0)
			std::cout << "size : " << size->getCapacity() << "ml\n";
	}
};

class FoodBuilder
{
public:
	virtual Name *getName() = 0;
	virtual Value *getValue() = 0;
	virtual Size *getSize() = 0;
};

class FoodA : public FoodBuilder
{
public:
	Name *getName() override
	{
		Name *name = new Name;
		name->set("pizza");
		return name;
	}
	Value *getValue() override
	{
		Value *value = new Value;
		value->set(120);
		return value;
	}
	Size *getSize() override
	{
		Size *size = new Size;
		size->set("Large");
		return size;
	}
};

class FoodB : public FoodBuilder
{
public:
	Name *getName() override
	{
		Name *name = new Name;
		name->set("Coca Cola");
		return name;
	}
	Value *getValue()
	{
		Value *value = new Value;
		value->setRMB(5);
		value->setJPY(160);
		return value;
	}
	Size *getSize()
	{
		Size *size = new Size;
		size->setCapacity(300);
		return size;
	}
};

class Restaurant
{
private:
	FoodBuilder *builder;

public:
	void setFood(FoodBuilder *b)
	{
		builder = b;
	}

	Food *getFood()
	{
		Food *food = new Food;
		food->setName(builder->getName());
		food->setValue(builder->getValue());
		food->setSize(builder->getSize());

		return food;
	}

};

int main()
{
	Restaurant menuA, menuB;
	std::cout << "Set Food\n";
	FoodA foodA;
	menuA.setFood(&foodA);
	FoodB foodB;
	menuB.setFood(&foodB);

	std::cout << "Food A : \n";
	Food *food_A;
	food_A = menuA.getFood();
	food_A->print();
	std::cout << "Food B : \n";
	Food *food_B;
	food_B = menuB.getFood();
	food_B->print();
}