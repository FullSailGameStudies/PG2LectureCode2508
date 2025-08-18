#pragma once
#include <string>
//do NOT include headers that THIS file does not need
//ex: iostream

class FullSailCourse
{
	//ACCESS Modifiers
	// public: ALL code can see it (i.e. change it, call it)
	// private (default): ONLY* this class can see it
	// protected: only this class and its descendents (inheritance) can see it
	// 
	//FIELDS (data members): DATA that describes the object
	//students, course name, assignments
	// in general, make them PRIVATE to protect the data
private:
	//naming convention:
	//camelCasingNamingConvention
	//class data members usually have something else
	//to set them apart from other variables
	//reason? to eliminate ambiguity, easier to read
	//  m_name, m_sName, mName, _name, name_
	std::string name_;
	std::string term_;//be consistent


	//  _stricmp  rand  push_back

	void Sample(std::string& name)
	{
		std::string nm = "Mr. Wayne";
		nm = "Joker";//local scope
		name = "Bruce";//scope beyond the method
		name_ = "PG2";
	}

public:
	//constructors (ctor)
	// Purpose: to initialize the fields of the class
	// 
	// ALL classes need at least 1 ctor so that
	//   you can create an object of the class
	// IF you do not create a ctor, the compiler
	//   will give you a default ctor
	// IF you create a ctor, the compiler's default ctor
	//   is NO longer available
	// 
	// SPECIAL methods
	// RULES:
	// 1) MUST be named the same as the class
	// 2) CANNOT have a return type (not even void)
	FullSailCourse()//default ctor (no parameters)
	{
	}

	//a parameterized ctor
	//a parameter for each field to set the data
	FullSailCourse(const std::string& name, const std::string& term) :
		//prefer to use the member initialization list
		name_(name),
		term_(term)
	{
		//name_ = name;
		//term_ = term;
	}

	//getters/setters are usually public
	// the public "interface" of the class
	// can be defined in the header
	// 
	//getters (accessors)
	//	the return type is the same as the field type
	//  no parameters (usually)
	//  simply returns the field
	//  usually const (they do NOT modify the object)
	const std::string& GetName() const { return name_; }
	const std::string& Term() const { return term_; }

	//setters (mutators)
	//  usually void return type
	//  at least 1 parameter to set the field to
	//  CANNOT be const b/c we're modifying the object
	//  good place for validation of the data
	void SetName(const std::string& name)
	{
		//validate the parameter before using it
		if (!name.empty() && name.size() <= 32)
		{
			name_ = name;
		}
	}
	void Term(const std::string& term)
	{
		if (term.size() > 0)
		{
			term_ = term;
		}
	}


private:
	//METHODS (member functions): what can this object DO
	//add a student, drop a student, add a grade, update grade
};

