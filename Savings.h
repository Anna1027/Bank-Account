#include "Account.h"
#include <string>

#ifndef SAVINGS_H
#define SAVINGS_H

class Savings : public Account {

  public:

  Savings(){};
  Savings(std::string, double, double);
  virtual ~Savings(){};
  double calculate_interest() const;
  double get_interest_rate() const;
  void set_interest_rate(double);

  virtual void accountStatement() const override;
  virtual void accountInfo() const override; 

  private:

  double interest_rate{0.0};

};


#endif