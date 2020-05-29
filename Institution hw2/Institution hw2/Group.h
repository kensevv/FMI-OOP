#pragma once
#include "Payer.h"

class Group
{
private:
	unsigned int group_id;
	Payer group_payer;
public:
	Group();

	void set_group_id(unsigned int _group_id);
	const unsigned int get_group_id()const;

	void set_group_payer(const Payer& _group_payer);
	const Payer& get_group_payer()const;
};

