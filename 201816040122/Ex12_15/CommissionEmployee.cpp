
//CommissionEmployee.cpp
//CommissionEmployee class member-function definitions.
#include<iostream>
#include"CommissionEmployee.h"  //CommissionEmployee class definition

using namespace std;

//constructor
CommissionEmployee::CommissionEmployee(const string &first,
                const string &last, const string &ssn, double sales,double rate)
                :Employee(first,last,ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}   //end CommissionEmployee constructor

//set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    if(sales>=0.0)
        grossSales=sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}   //end function setGrossSales

//return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

//set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
    if(rate>=0.0&&rate<1.0)
        commissionRate=rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

//return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

//calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate()*getGrossSales();
}

//print CommissionEmployee's information
void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print();  //code reuse
    cout << "gross sales; " << getGrossSales()<<endl;
      cout << "commission rate: " << getCommissionRate() << endl;
      cout<<"the earnings is:"<<earnings()<<endl;
}