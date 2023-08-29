#include <iostream>

using namespace std;

class Rectangle
{
private:
	float lenght;
	float height;
	static int RectanglesCount;

public:
	Rectangle() : lenght(0.0), height(0.0) { RectanglesCount++; }
	Rectangle(float	l, float h) : lenght(l), height(h) { RectanglesCount++; }

	float GetArea()
	{
		return lenght * height;
	}
	float GetPerimetr()
	{
		return (lenght + height) * 2;
	}
	static int GetRectanglesCount()
	{
		return RectanglesCount;
	}
};

int Rectangle::RectanglesCount = 0;

int main()
{
	Rectangle rect1;
	Rectangle rect2(4, 2);

	cout << "First rect area and perimetr: " << rect1.GetArea() << " and: " << rect1.GetPerimetr() << endl;
	cout << "Second rect area and perimetr: " << rect2.GetArea() << " and: " << rect2.GetPerimetr() << endl;
	cout << "Rectangle count: " << Rectangle::GetRectanglesCount() << endl;
}