#include "Institution.h"

void Institution::copy(const Institution& other)
{
	set_institution_name(other.institution_name);
	set_institution_id(other.institution_id);
}

Institution::Institution()
{
	set_institution_name("Default");
	set_institution_id(0);
}

Institution::Institution(const Institution& other)
{
	copy(other);
}

Institution& Institution::operator=(const Institution& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

Institution::Institution(unsigned int new_institution_id, std::string new_institution_name)
{
	set_institution_id(new_institution_id);
	set_institution_name(new_institution_name);
}

void Institution::set_institution_id(unsigned int newInstitutionId)
{
	this->institution_id = newInstitutionId;
}

unsigned int Institution::get_institution_id() const
{
	return this->institution_id;
}

void Institution::set_institution_name(const std::string& newInstitutionName)
{
	this->institution_name = newInstitutionName;
}

const std::string& Institution::get_institution_name() const
{
	return this->institution_name;
}

std::ostream& operator<<(std::ostream& out, const Institution& current)
{
	// TODO: insert return statement here
	return out;
}

std::istream& operator>>(std::istream& in, Institution& current)
{
	// TODO: insert return statement here
	return in;
}
