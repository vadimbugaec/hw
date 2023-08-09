#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int nummarks = 4;

struct Student
{
	const char* name;
	int marks[nummarks];
};

double avgmark(const Student& student)
{
	double sum = 0;
	for (int i = 0; i < nummarks; i++)
	{
		sum += student.marks[i];
	}
	return sum / nummarks;
}

bool AvgSwap(const Student& student1, const Student& student2) {
	return avgmark(student1) > avgmark(student2);
}

void sortByAverage(Student students[], int size) 
{
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (avgmark(students[j]) < avgmark(students[j + 1])) 
			{
				swap(students[j], students[j + 1]);
			}
		}
	}
}

const Student& BestStudent(Student students[], int size) 
{
	sortByAverage(students, size);
	return students[0];
}

int TopStudents(Student students[], int size, double thereshold) 
{
	int count = 0;
	for (int i = 0; i < size; i++) 
	{
		if (avgmark(students[i]) > thereshold) 
		{
			count++;
		}
	}
	return count;
}

int main()
{
	//10-ти бальна система оцінювання
	const int studentcount = 6;
	Student students[studentcount] =
	{
	{ "Vasya", {8, 7, 8, 10,} },
	{ "Petro", { 5, 7, 6, 6 } },
	{ "Valeria",{9, 10, 10, 9} },
	{ "Ivan" , { 6, 6, 5, 6 } },
	{ "Bohdan", {9, 10, 10, 10} },
	{ "Valentina",{4, 5, 6, 6} }
	};

	sort(students, students + studentcount, AvgSwap);

	for (int i = 0; i < studentcount; i++)
	{
		cout << "Student " << students[i].name << " has an avg mark: " << avgmark(students[i]) << endl;
	}
	cout << endl;
	
	const Student& topStudent = BestStudent(students, studentcount);
	cout << "Top Student: " << topStudent.name << " with an average mark of: " << avgmark(topStudent) << endl;

	const double thereshold = 7.5;
	int aboveAverageCount = TopStudents(students, studentcount, thereshold);
	cout << "\nNumber of students with an average mark above " << thereshold << ": " << aboveAverageCount << endl;


}
