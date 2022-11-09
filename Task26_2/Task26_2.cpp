#include <iostream>
#include<map>
#include<string>
#include<vector>

class TelephoneDirectory
{
private:
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
	Phone* phone = new Phone();
	std::string name;
	std::string telefon;
	std::string command;
	std::string sms;
	std::vector<std::string> numberPhone;
	while (true)
	{
		std::cout << "Input command (add, call, sms, exit) : ";
		std::cin >> command;
		if (command == "add")
		{
			std::cout << "Input name : ";
			std::cin >> name;
			std::cout << "Input phone number (+7<10 numbers>) : ";
			std::cin >> telefon;
			if (phone->checkingTheInput(telefon))
			{
				phone->setBase(name, telefon);
			}
			else
			{
				std::cout << "Phone number entered incorrectly" << std::endl;
			}	
		}
		if (command == "call")
		{
			std::cout << "Input name or number phone ";
			std::cin >> command;
			if (command.size() == 12 && command[0] == '+' || command[1] == '7')
			{
				phone->getCallName(name, command);
				std::cout << "CALL" << " " << command << " " << "NAME : " << name<<std::endl;
			}
			else
			{
				phone->getCallPhone(command, numberPhone);
				if (numberPhone.size() > 1)
				{
					int temp = 1;
					std::cout << "What phone number do you want to call?\n";
					for (auto i : numberPhone)
					{
						std::cout << temp <<"  "<<command<<" "<< i << std::endl;
						temp++;
					}
					std::cin >> temp;
					std::cout << "CALL" << "  " << "NAME : " << command <<" "<<numberPhone.at(temp-1)<< std::endl;
				}
				else
				{
					std::cout << "CALL" << "  " << "NAME : " << command << " " << numberPhone[0] << std::endl;
				}
			}
		}
		if (command == "sms")
		{
			std::cout << "Input name or number phone ";
			std::cin >> command;
			if (command.size() == 12 && command[0] == '+' || command[1] == '7')
			{
				phone->getCallName(name, command);
				std::cin.ignore();
				std::cout << "Input SMS :";
				std::getline(std::cin, sms);
				std::cout << "SMS sent" << " " << command << " " << "NAME : " << name << std::endl;
			}
			else
			{
				phone->getCallPhone(command, numberPhone);
				if (numberPhone.size() > 1)
				{
					int temp = 1;
					std::cout << "What phone number do you want to call?\n";
					for (auto i : numberPhone)
					{
						std::cout << temp << "  " << command << " " << i << std::endl;
						temp++;
					}
					std::cin >> temp;
					std::cin.ignore();
					std::cout << "Input SMS :";
					std::getline(std::cin, sms);
					std::cout << "SMS sent" << "  " << "NAME : " << command << " " << numberPhone.at(temp - 1) << std::endl;
				}
				else
				{
					std::cin.ignore();
					std::cout << "Input SMS :";
					std::getline(std::cin, sms);
					std::cout << "SMS sent" << "  " << "NAME : " << command << " " << numberPhone[0] << std::endl;
				}
			}
		}
		if (command == "exit")
		{
			break;
		}
	}
	delete phone;
}