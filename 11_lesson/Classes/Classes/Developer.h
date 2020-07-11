#pragma once

#include "Worker.h"

class Developer : public Worker
{
	// public -> public
	// private -> private
public:
	//void SetFirstName(const std::string& name) {
	//	//m_firstname = name;						// !!! doesn't allow
	//}
	uint32_t GetSalary() const;

};

