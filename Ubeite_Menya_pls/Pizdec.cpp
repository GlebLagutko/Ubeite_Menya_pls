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
		a = a / stud.subject.size();
		stud.average = a;
		StudentVector.push_back(stud);
	}
	return StudentVector;
}

void Menu(string way1,string way2)
{
	auto a1 = FillVector(way1);
	wofstream fout("C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\output.txt");
	fout << "First group : " << endl;;
	Average(a1,fout);
	fout << "Median : " << FindMedian(a1);
	fout << endl;
	auto a2 = FillVector(way2);
	fout << "Second group : " << endl;
	Average(a2, fout);
	fout << "Median : " << FindMedian(a2);
}

int main()
{
	Menu("C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\KR.txt", "C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\KR2.txt");
	system("pause");
}