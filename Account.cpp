#include "Account.h"
#include <iostream>

Account::Account(std::string accountName, double startingBalance) 
: name{accountName} // member initializer list
{ 
  if (startingBalance > 0){
    balance = startingBalance;
  }
}
    
Account::~Account(){
}
    
void Account::deposit(double depositAmount){
  if (depositAmount > 0){
    balance += depositAmount;
    addTransaction(depositAmount);
  }
}
   
void Account::withdraw(double withdrawAmount){
  if (withdrawAmount > 0){
    if (withdrawAmount <= balance){
      balance -= withdrawAmount;
      addTransaction(-withdrawAmount);
    }
    else{
      std::cout << "Withdrawal amount exceeds balance.\n";
    }
  }
}

void Account::addTransaction(double transaction){
  transactions.push_back(transaction);
}

double Account::getBalance() const {
  return balance;
}

void Account::setName(std::string accountName){
  name = accountName;
}

std::string Account::getName() const {
  return name;
}



void Account::accountStatement() const {
  std::cout << "\nACCOUNT STATEMENT\n=================\n" << getName();
  for (int i = 0; i < transactions.size(); i++){
    if (transactions[i] > 0){
      std::cout << "\nDeposit ";
    }
    else{
      std::cout << "\nWithdrawal ";
    }
    std::cout << transactions[i];
  }
  std::cout << std::endl;
}


void Account::accountInfo() const{
  std::cout << "Name: " << getName() << "\nBalance: " << getBalance() << "\n";
}
