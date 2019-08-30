#include "Account.h"
#include "DebitCard.h"
#include <string>

#ifndef CHECKING_H
#define CHECKING_H

class Checking : public Account {

public:
  Checking(){};
  Checking(std::string, double);
  virtual ~Checking(){};
  void issue_debit_card();
  bool has_debit_card() const;
  DebitCard* get_checking_card() const;
  virtual void accountStatement() const override;
  virtual void accountInfo() const override;

private:
DebitCard* checking_card{nullptr};

};


#endif