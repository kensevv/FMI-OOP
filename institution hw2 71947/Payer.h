#pragma once
#include <iostream>
#include<string>

class Payer
{
private:
	std::string payer_name;

	void copy(const Payer& other);
public:
	Payer();
	Payer(const Payer& other);
	Payer& operator=(const Payer& other);
	Payer(const std::string& new_payer_name);

	//bool payer_member_rule(const Person& person, const Group& group);

	void set_payer_name(const std::string& new_payer_name);
	const std::string& get_payer_name()const;

	friend std::ostream& operator<<(std::ostream& out, const Payer& current);
	friend std::istream& operator>>(std::istream& in, Payer& current);
};

