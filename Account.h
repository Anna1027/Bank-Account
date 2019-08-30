#include <string>
#include <vector>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

  public:  
    Account(std::string, double);
    Account(){};
    virtual ~Account();
    
    void deposit(double);
    void withdraw(double);
    double getBalance() const;
    void setName(std::string);
    std::string getName() const;
    virtual void accountStatement() const = 0;
    virtual void accountInfo() const = 0;
      
  protected:
    std::vector<double> transactions;

  private: 
    std::string name;
    double balance{0};
    void addTransaction(double);
};

#endif