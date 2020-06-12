#pragma once
#include <iostream>
#include <string>
class Person
{
private:
	std::string person_name;
	unsigned int insurance_id;

	void copy(const Person& other);
public:
	Person();
	Person(const Person& other);
	Person& operator=(const Person& other);
	Person(std::string new_person_name, unsigned int new_insurance_id); //..

	void set_person_name(const std::string& newPersonName);
	const std::string& get_person_name() const;

	void set_insurance_d(unsigned int newInsuranceId);
	unsigned int get_insurance_id()const;

	friend std::ostream& operator<<(std::ostream& out, const Person& current);
	friend std::istream& operator>>(std::istream& in, Person& current);
}; 