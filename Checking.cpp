#include "Checking.h"
#include <iostream>

Checking::Checking(std::string name, double start_bal):
Account(name, start_bal)
{
}

void Checking::issue_debit_card(){
  checking_card = new DebitCard(getName());
  checking_card->change_pin();
}

DebitCard* Checking::get_checking_card() const{
  if (checking_card != nullptr)
    return checking_card;
  else 
    return nullptr;
}

bool Checking::has_debit_card() const{
  if (checking_card != nullptr){
    return true;
  }
  else{
    return false;
  }
}

void Checking::accountInfo() const {
  std::cout << "\nAccount name: " << getName();
  std::cout << "\tBalance: $" << getBalance();
  std::cout << "\nDebit Card Issued: ";
  if (has_debit_card())
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}


void Checking::accountStatement() const {
  std::cout << "\n\nCHECKING ACCOUNT STATEMENT\n=========================\n" << getName();
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