#include "Person.h"

void Person::copy(const Person& other)
{
	set_person_name(other.person_name);
	set_insurance_d(other.insurance_id);
}

Person::Person()
{
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
Person::Person(std::string new_person_name, size_t new_insurance_id)
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

void Person::set_insurance_d(size_t newInsuranceId)
{
	this->insurance_id = newInsuranceId;
}

size_t Person::get_insurance_id() const
{
	return this->insurance_id;
}
