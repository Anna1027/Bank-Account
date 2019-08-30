#include "Account.h"
#include "Savings.h"
#include <string>
#include <iostream>
#include <iomanip>

Savings::Savings(std::string name, double start_bal, double start_rate):
Account(name, start_bal)
{
  if (start_rate > 0 && start_rate < 1){
    interest_rate = start_rate;
  }
}

double Savings::get_interest_rate() const{
  return interest_rate;
}

void Savings::set_interest_rate(double new_rate){
  if (new_rate > 0 && new_rate < 1){
    interest_rate = new_rate;
  }
}

double Savings::calculate_interest() const{
  return getBalance() * interest_rate;
}

void Savings::accountInfo() const {
  std::cout << "\nAccount name: " << getName();
  std::cout << "\tBalance: $" << getBalance();
  std::cout << "\nInterest Rate: " << get_interest_rate() << "\n";
}

void Savings::accountStatement() const {
  std::cout << "\nSAVINGS ACCOUNT STATEMENT\n=======================\n" << getName();
  for (int i = 0; i < transactions.size(); i++){
    if (transactions[i] > 0){
      std::cout << "\nDeposit ";
    }
    else{
      std::cout << "\nWithdrawal ";
    }
    std::cout << transactions[i];
  }
  std::cout << "\nInterest Earned: " << std::fixed << std::setprecision(2) << calculate_interest() << "\n";
}