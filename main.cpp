//https://repl.it/@jholst/lab-10-start

#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Retirement.h"
#include <iostream>
#include <fstream> // istream
#include <sstream> // istringstream
#include <vector>
#include <string>
using namespace std;

int main(){
  vector<Account*> accounts;
  
  // try to open file
  ifstream infile{"accounts.txt"};
  if (!infile){
    cout << "Could not open file.";
  }
  else{
    string acct_type;
    string name;
    string start_balance;
    string issue_atm;
    string interest_rate;
    string ret_type; // for lab 10
    string row;
    while (getline(infile, row)){
      istringstream input{row};
      getline(input, acct_type, ','); //get a_t
      getline(input, name, ',');
      getline(input, start_balance, ',');
      if (acct_type == "c"){
        getline(input, issue_atm);
        Checking* temp = new Checking{name, stod(start_balance)};
        if (issue_atm == "y"){
          temp->issue_debit_card();
        }
        accounts.push_back(temp);
      }
      else if (acct_type == "s"){
        getline(input, interest_rate);
        accounts.push_back(new Savings{name, stod(start_balance), stod(interest_rate)});
      }
      // else if (acct_type == "r") {}// lab 10
      else if (acct_type== "r"){
        getline(input,ret_type);
        accounts.push_back(new Retirement{name,stod(start_balance),ret_type} );
      }
    }// end while
  } // end else
  for (int i = 0; i < accounts.size(); i++){
    accounts[i]->accountStatement();
  }
  for (int i = 0; i < accounts.size(); i++){
    accounts[i]->accountInfo();
  }

} // end main