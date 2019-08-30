#include "DebitCard.h"
#include <string>
#include <ctime>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>


DebitCard::DebitCard(std::string name):
name_on_card{name}
{
  card_number = std::to_string(rand()% 10000 + 10000);
  time_t now = time(0);
  tm *loctime = localtime(&now);
  int year = 1900 + loctime->tm_year;
  int month = 1 + loctime->tm_mon;
  expiration_month = month;
  expiration_year = year + 2;
}

std::string DebitCard::get_name_on_card() const{
  return name_on_card;
}

std::string DebitCard::get_card_number() const{
  return card_number;
}

std::string DebitCard::get_expiration_date() const{
  std::ostringstream output;
  output << expiration_month << "/" << expiration_year;
  return output.str();
}

bool DebitCard::is_pin_set() const{
  if (pin == "0000"){
    return false;
  }
  else{
    return true;
  }
}

void DebitCard::change_pin(){
  std::string new_pin;
  std::cout << "\nEnter new pin for " << get_name_on_card() << ": ";
  std::cin >> std::setw(4) >> new_pin;
  while (new_pin == "0000" || new_pin.size() < 4){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nEnter new pin: ";
    std::cin >> std::setw(4) >> new_pin;
  }
}


std::ostream& operator<<(std::ostream & output, const DebitCard* card){
  output << "\nName on Card: " << card->name_on_card<< 
  "\nCard Number: " << card->card_number << 
  "\nExpiration Date: " << card->get_expiration_date() << std::endl;
  return output;
}
