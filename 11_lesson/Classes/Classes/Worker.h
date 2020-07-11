#pragma once
#include <string>

class Worker {
	    // all fields and methods are PRIVATE (default)
	    // good rules:
	    //      public -> protected -> private (in the end)
	    //      don't public members
	public:
		Worker();
	
		Worker(
			const std::string& firstname, 
			const std::string& secondname, 
			const std::string& position);
		std::string GetFullName() const;
		void GetFullName(std::string& fullName) const;
		std::string GetFirstName() const;
		void SetFirstName(const std::string& name);
		void SetFirstName(const char* name);
	    //std::string m_firstname;
	private:
		Worker(const std::string& firstname, const std::string& secondname);
	private:
	    std::string m_firstname;
	    std::string m_secondname;
	    std::string m_position;
	};

