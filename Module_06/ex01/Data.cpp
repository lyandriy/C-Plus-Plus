/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:30:05 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 17:25:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(){}

Data::~Data(){}

Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &other)
{
	this->members = other.members;
	return (*this);
}

Data::Data(int _members) : members(_members) {}