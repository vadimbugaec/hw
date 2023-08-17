#include <iostream>

using namespace std;

class Rectangle
{
private:
	float lenght;
	float height;

public:
	Rectangle() : lenght(0.0), height(0.0) {}
	Rectangle(float	l, float h) : lenght(l), height(h) {}

	float GetArea()
	{
		return lenght * height;
	}
	float GetPerimetr()
	{
		return (lenght + height) * 2;
	}
};

int main()
{
	Rectangle rect1;
	Rectangle rect2(4, 2);

	cout << "First rect area and perimetr: " << rect1.GetArea() << " and: " << rect1.GetPerimetr() << endl;
	cout << "Second rect area and perimetr: " << rect2.GetArea() << " and: " << rect2.GetPerimetr() << endl;
}