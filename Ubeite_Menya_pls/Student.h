#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;

class Student
{
public :
	wstring name;
	wstring surname;
	wstring fatherName;
	map<wstring,int> subject;
	int average;

	Student() {}

	Student(const Student& other)
		: name(other.name),
		surname(other.surname),
		fatherName(other.fatherName),
		subject(other.subject),
	    average(other.average)
	{
	}

	Student(Student&& other)
		: name(std::move(other.name)),
		surname(std::move(other.surname)),
		fatherName(std::move(other.fatherName)),
		subject(std::move(other.subject)),
		average(std::move(other.average))
	{
	}

	void SetAverage(int a)
	{
		this->average = a;
	}

	int GetAverage()
	{
		return this->average;
	}

	wstring GetName() const
	{
		return name;
	}

	void SetName(wstring name)
	{
		this->name = name;
	}


	wstring GetSurname() const
	{
		return surname;
	}

	void SetSurname(wstring surname)
	{
		this->surname = surname;
	}

	wstring GetFatherNAme() const
	{
		return fatherName;
	}

	void SetFatherName(wstring father_name)
	{
		fatherName = father_name;
	}

	map<wstring, int> GetSubject() const
	{
		return subject;
	}

	void SetSubject(map<wstring,int> subject)
	{
		this->subject = subject;
	}



	friend bool operator==(const Student& lhs, const Student& rhs)
	{
		return lhs.name == rhs.name
			&& lhs.surname == rhs.surname
			&& lhs.fatherName == rhs.fatherName
			&& lhs.subject == rhs.subject
		    && lhs.average == rhs.average;
	}

	friend bool operator!=(const Student& lhs, const Student& rhs)
	{
		return !(lhs == rhs);
	}

	Student& operator=(const Student& other)
	{
		if (this == &other)
			return *this;
		name = other.name;
		surname = other.surname;
		fatherName = other.fatherName;
		subject = other.subject;
		average = other.average;
		return *this;
	}

	Student& operator=(Student&& other)
	{
		if (this == &other)
			return *this;
		name = std::move(other.name);
		surname = std::move(other.surname);
		fatherName = std::move(other.fatherName);
		subject = std::move(other.subject);
		average = std::move(other.average);
		return *this;
	}
	
};