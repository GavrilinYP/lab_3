#include "Temperature.h"
using  namespace std;

char Scale[]="CKF";
istream & operator >> (istream &in, Temperature &Temp){
    in >> Temp.temp;
    in >> Temp.scale;}

double convert (const Temperature &Temp, char scale_to) {
    double T_Kel;
    T_Kel = Temp.temp;
    switch (Temp.scale){
    case 'C':
    case 'c':
        T_Kel+=273;
        break;
    case 'F':
    case 'f':
        T_Kel=((5.0/9)*(T_Kel-32)+273);
        break;
    }
    switch (scale_to){
    case 'C':
    case 'c':
        T_Kel-=273;
        break;
    case 'F':
    case 'f':
        T_Kel=((9.0/5)*(T_Kel - 273)+32);
        break;
    }
    return T_Kel;
}
bool operator< (const Temperature& lhs, const Temperature& rhs)
{
    return convert(lhs,'K')<convert(rhs, 'K');
}
bool operator> (const Temperature& lhs, const Temperature& rhs)
{
    return convert(lhs,'K')>convert(rhs, 'K');
}
Temperature operator- (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')-convert(rhs, 'K');
    ret_temp.scale='K';
    return  ret_temp;
}
Temperature operator/ (const Temperature& lhs, const Temperature& rhs)
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')/convert(rhs, 'K');
    ret_temp.scale='K';
    return  ret_temp;
}
