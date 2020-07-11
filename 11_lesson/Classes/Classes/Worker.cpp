#include "Worker.h"

Worker::Worker()
{
}

Worker::Worker(
	const std::string& firstname, 
	const std::string& secondname, 
	const std::string& position) :
	m_firstname(firstname),
	m_secondname(secondname), 
	m_position{ position }			// c++11 uniform inizialization
{
	//m_firstname = firstname;
	//m_secondname = secondname;
	//m_position = position;
}
Worker::Worker(const std::string& firstname, const std::string& secondname)
{
	m_firstname = firstname;
	m_secondname = secondname;
}
std::string Worker::GetFullName() const {
	return m_firstname + " " + m_secondname;
}
void Worker::GetFullName(std::string& fullName) const { // !! useless
	fullName =  m_firstname + " " + m_secondname;
}
std::string Worker::GetFirstName() const {
	return m_firstname;
}

void Worker::SetFirstName(const std::string& name) {
	m_firstname = name;
}

void Worker::SetFirstName(const char* name)
{
	m_firstname = name;
}

