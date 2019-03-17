#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <sstream>
#include <map>
#include <fstream>
#include "Student.h"
#include <queue>
#include <codecvt>

using namespace std;

int FindMedian(vector<Student>& studentVector)
{
	vector<int> marks;
	for (auto a : studentVector)
		marks.push_back(a.average); 
	sort(marks.begin(), marks.end());
	int median;
	if (marks.size() % 2 == 0)
	{
		median = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2;
	}
	else
	{
		median = marks[marks.size() / 2];
	}

	return median;
}

void Average(vector<Student>& studentVector,wofstream& fout)
{

	for (auto stud : studentVector)
	{
		fout << stud.name << " " << stud.surname << " " << stud.fatherName << " average : ";
		fout << stud.average << endl;
	}

}


vector<Student> FillVector(string way)
{

	vector<Student> StudentVector;
	wifstream wifile;
	wifile.open(way);
	wifile.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	Student stud;
	while(!wifile.eof())
	{
		stud.subject.clear();
		wstring wstr;
		wstring subj;
		int mark;
		getline(wifile, wstr);
		wstringstream str_stream(wstr);
		str_stream >> stud.name >> stud.surname >> stud.fatherName;
		getline(wifile, wstr);
		wstringstream str_stream1(wstr);
		while (!str_stream1.eof())
		{
			str_stream1 >> subj >> mark;
			stud.subject.insert(pair<wstring, int>(subj, mark));
		}
		int a = 0;
		for (auto b : stud.subject)
		{
			a = a + b.second;
		}
		a = a / 3;
		stud.average = a;

		StudentVector.push_back(stud);
	}

	return StudentVector;
}

void Menu(string way)
{
	auto a = FillVector(way);
	wofstream fout("C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\output.txt");
	Average(a,fout);
	FindMedian(a);

}

int main()
{
	Menu("C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\KR.txt");

	system("pause");
}