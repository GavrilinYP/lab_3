#include <iostream>
#include "Temperature.h"
#include <sstream>
#include <cassert>

using namespace std;
int main (){
    Temperature Temp;
    istringstream iss1("10C");
    iss1>>Temp;
    assert(Temp.temp == 10);
    assert(Temp.scale == 'C');
    istringstream iss2("0K");
    iss2>>Temp;
    assert(Temp.temp == 0);
    assert(Temp.scale == 'K');
    istringstream iss3("-400F");
    iss3>>Temp;
    assert(Temp.temp == -400);
    assert(Temp.scale == 'F');
    istringstream iss4("0K");
    iss4>>Temp;
    assert(Temp.temp >= 0);
    assert(Temp.scale == 'K');
}