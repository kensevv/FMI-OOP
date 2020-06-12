#include "Group.h"

void Group::copy(const Group& other)
{
	Institution::copy(other);
	set_group_id(other.group_id);
	set_group_payer(other.group_payer);
}

Group::Group() : Institution()
{
	set_group_id(0);
}


Group::Group(const Group& other)
{
	copy(other);
}

Group& Group::operator=(const Group& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}


Group::Group(unsigned int new_institution_id, std::string new_institution_name, unsigned int new_group_id, const Payer& new_group_payer)
	: Institution(new_institution_id, new_institution_name)
{
	set_group_id(new_group_id);
	set_group_payer(new_group_payer);
}

void Group::set_group_id(unsigned int _group_id)
{
	this->group_id = _group_id;
}

const unsigned int Group::get_group_id() const
{
	return this->group_id;
}

void Group::set_group_payer(const Payer& _group_payer)
{
	this->group_payer = _group_payer;
}

const Payer& Group::get_group_payer() const
{
	return this->group_payer;
}

std::ostream& operator<<(std::ostream& out, const Group& current)
{
	// TODO: insert return statement here
	return out;
}

std::istream& operator>>(std::istream& in, Group& current)
{
	// TODO: insert return statement here
	return in;
}
