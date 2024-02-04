#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

std::string Contact::getFirstName(void)
{
	return (this->FirstName);
}

std::string Contact::getLastName(void)
{
	return (this->LastName);
}

std::string Contact::getNickname(void)
{
	return (this->Nickname);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->PhoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->DarkestSecret);
}

void Contact::setFirstName(std::string name)
{
	this->FirstName = name;
}

void Contact::setLastName(std::string name)
{
	this->LastName = name;
}

void Contact::setNickname(std::string name)
{
	this->Nickname = name;
}

void Contact::setPhoneNumber(std::string name)
{
	this->PhoneNumber = name;
}

void Contact::setDarkestSecret(std::string name)
{
	this->DarkestSecret = name;
}
