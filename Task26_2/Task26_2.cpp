#include <iostream>
#include<map>
#include<string>
#include<vector>

class TelephoneDirectory
{
private:
int number = 0;
	std::map <std::string, std::vector <std::string>> name;
	std::map <std::string, std::string> call;
public:

	void setNamePhone(std::string &namesPhone, std::string &phone)
	{
		if (name.find(namesPhone) != name.end())
		{
			name[namesPhone].push_back(phone);
			call.insert(std::pair<std::string, std::string>(phone, namesPhone));
		}
		else
		{
			call.insert(std::pair<std::string, std::string>(phone, namesPhone));
			name[namesPhone].push_back(phone);
		}
	}
	void getName(std::string &name, std::string &phone)
	{
		auto findMap = call.find(phone);
		if (findMap != call.end()) 
		{
			name = findMap->second;
		}
		else 
		{
			std::cout << "This number is not in the database!" << std::endl;
		}
	}
	void getPhone(std::string names, std::vector<std::string> &numbepPhones)
	{
		auto findMap = name.find(names);
		if (findMap != name.end())
		{
			numbepPhones = name[names];			
		}
		else 
		{
			std::cout << "This name is not in the database!" << std::endl;
		}
	}
};

class Phone
{
private:

	TelephoneDirectory database;

public:

	void setBase(std::string &name, std::string &phone)
	{
		database.setNamePhone(name, phone);
	}

	void getCallName(std::string &namePhone, std::string &phone)
	{
			database.getName(namePhone, phone);
	}
	void getCallPhone(std::string &namePhone, std::vector<std::string> &numbepPhones)
	{
		database.getPhone(namePhone, numbepPhones);
	}
	bool checkingTheInput(std::string phone)
	{
		if (phone.size() != 12 || phone[0]!='+'|| phone[1]!='7')
			return false;
		return true;
	}
};
int main()
{
	

	
}