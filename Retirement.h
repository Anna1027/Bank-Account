#include "Account.h"
#include <string>

#ifndef RETIREMENT_H
#define RETIREMENT_H

class Retirement: public Account{

public:
  Retirement(std::string, double, std::string); // name, balance, ret_type
  Retirement(){};
  virtual ~Retirement(){};
  virtual void accountStatement() const override;
  virtual void accountInfo() const override;
  std::string get_ret_type() const;

private:
  std::string ret_type;

};

#endif