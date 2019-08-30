#include "Retirement.h"
#include <iostream>

Retirement::Retirement (std::string name, double balance,std::string ret_type):
Account(name,balance){

 this-> ret_type=ret_type;
}

void Retirement::accountStatement()const  {

if (ret_type == "r"){
  std::cout<<"ROTH ACCOUNT STATEMENT"<<"\n";
}
else if (ret_type == "t"){
  std::cout<<"TRADITIONAL IRA ACCOUNT STATEMENT"<<"\n";
}
else {
  std::cout<<"RETIREMENT ACCOUNT STATEMENT"<<"\n";
}
}

void Retirement::accountInfo()const{
 std::cout << "Name: " << getName() << "\nBalance: " << getBalance() << "\n";

  if (ret_type == "r"){
  std::cout<<"ROTH ACCOUNT INFO"<<"\n";
}
else if (ret_type == "t"){
  std::cout<<"TRADITIONAL IRA ACCOUNT INFO "<<"\n";
}
else {
  std::cout<<"RETIREMENT ACCOUNT INFO"<<"\n";
}
}
