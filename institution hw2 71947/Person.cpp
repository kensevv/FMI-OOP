#include "Person.h"

void Person::copy(const Person& other)
{
	set_person_name(other.person_name);
	set_insurance_d(other.insurance_id);
}

Person::Person()
{
	set_person_name("Default");
	set_insurance_d(0);
}

Person::Person(const Person& other)
{
	copy(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}
Person::Person(std::string new_person_name, unsigned int new_insurance_id)
{
	set_person_name(new_person_name);
	set_insurance_d(new_insurance_id);
}

void Person::set_person_name(const std::string& newPersonName)
{
	this->person_name = newPersonName;
}

const std::string& Person::get_person_name() const
{
	return this->person_name;
}

void Person::set_insurance_d(unsigned int newInsuranceId)
{
	this->insurance_id = newInsuranceId;
}

unsigned int Person::get_insurance_id() const
{
	return this->insurance_id;
}

std::ostream& operator<<(std::ostream& out, const Person& current)
{
	out << current.person_name << " " << current.insurance_id << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Person& current)
{
	std::cout << "Person name: ";
	in >> current.person_name;
	std::cout << "Insurance ID";
	in >> current.insurance_id;

	return in;
}
