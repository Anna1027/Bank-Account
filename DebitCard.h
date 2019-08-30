#include <string>
#include <iostream>

#ifndef DEBITCARD_H
#define DEBITCARD_H

class DebitCard {

friend class Checking;
friend std::ostream& operator<<(std::ostream &, const DebitCard*);

public:

  std::string get_name_on_card() const;
  std::string get_card_number() const;
  std::string get_expiration_date() const;
  bool is_pin_set() const;

private:

  DebitCard(){};
  DebitCard(std::string);
  void change_pin();

  std::string card_number{};
  std::string name_on_card{};
  unsigned int expiration_month{0};
  unsigned int expiration_year{0};
  std::string pin{"0000"};

};

#endif