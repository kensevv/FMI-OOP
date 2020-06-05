#include "Payer.h"

Payer::Payer()
{
}

void Payer::set_payer_name(const std::string& new_payer_name)
{
	this->payer_name = new_payer_name;
}

const std::string& Payer::get_payer_name() const
{
	return payer_name;
}
