#ifndef LAB01_TEMPERATURE_H
#define LAB01_TEMPERATURE_H

#include <iostream>
#include <sstream>
using namespace std;

struct Temperature{
    char scale;
    double temp;
};
istream & operator >> (istream &in, Temperature &Temp);
double convert (const Temperature &Temp, char scale_to);
bool operator< (const Temperature& lhs, const Temperature& rhs);
bool operator> (const Temperature& lhs, const Temperature& rhs);
Temperature operator- (const Temperature& lhs, const Temperature& rhs);
Temperature operator/ (const Temperature& lhs, const Temperature& rhs);
#endif