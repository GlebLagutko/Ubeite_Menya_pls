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

void ShowAverageForStudent(Student& stud,wofstream& fout)
{
	
	int a = 0;
	for(auto b : stud.subject )
	{
		a = a + b.second;
	}
	a = a / 3;
	fout << stud.name << " " << stud.surname << " " << stud.fatherName << " average : ";
	fout << a << endl;
}

void Average(vector<Student>& studentVector,wofstream& fout)
{

	for (auto a : studentVector)
		ShowAverageForStudent(a,fout);

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

		StudentVector.push_back(stud);
	}

	return StudentVector;
}

void Menu(string way)
{
	auto a = FillVector(way);
	wofstream fout("C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\output.txt");
	Average(a,fout);

}

int main()
{
	Menu("C:\\Users\\Dell\\source\\repos\\Ubeite_Menya_pls\\KR.txt");

	system("pause");
}