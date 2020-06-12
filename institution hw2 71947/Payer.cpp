#include "Payer.h"

void Payer::copy(const Payer& other)
{
	set_payer_name(other.payer_name);
}

Payer::Payer()
{
	set_payer_name("Default");
}

Payer::Payer(const Payer& other)
{
	copy(other);
}

Payer& Payer::operator=(const Payer& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

Payer::Payer(const std::string& new_payer_name)
{
	set_payer_name(new_payer_name);
}

//bool Payer::payer_member_rule(const Person& person,  const Group& group)
//{	return true;}

void Payer::set_payer_name(const std::string& new_payer_name)
{
	this->payer_name = new_payer_name;
}

const std::string& Payer::get_payer_name() const
{
	return payer_name;
}

std::ostream& operator<<(std::ostream& out, const Payer& current)
{
	// TODO: insert return statement here
	return out;
}

std::istream& operator>>(std::istream& in, Payer& current)
{
	// TODO: insert return statement here
	return in;
}
