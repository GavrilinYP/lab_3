#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

char Scale[]="CKF";
struct Temperature{
    char scale;
    double temp;
};
istream & operator >> (istream &in, Temperature &Temp);
istream & operator >> (istream &in, Temperature &Temp){
    in >> Temp.temp;
    in >> Temp.scale;}
void test_temperature_input(){
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
}


int
main() {
    test_temperature_input();
    double convert (const Temperature &Temp, char scale_to){
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
    size_t count;
   char el, probel, otstup;
   int proverka;
    double kof;
    cout<<"\n chislo el ";
    cin >> count;
    vector<double> xs(count);
    cout<<"\n vvedite  "<<count<<" elementov ";
    for (size_t i = 0; i < count; i++) {
        cin >> xs[i];

    }
    size_t bin_count;
    cout<<"\n chislo korzin ";
    cin >> bin_count;
    double min = xs[0], max = xs[0];
    for (double x:xs) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
    vector<size_t> bins(bin_count, 0);
    for (double x:xs) {
        size_t index = (x - min) / (max - min) * bin_count;
        if (x == max) {
            index--;
        }
        bins[index]++;
    }
    kof=1;
    if (max>76)
        kof=(1-(max-76)/max);
    cout<<"vibirite_simvol_dlya_elementa";
    cin>>el;
    proverka=el;
    cout<<proverka;
    if (proverka==13||proverka==9)
        cout<<"ERROR";
    else{
        cout<<"vibirite_simvol_dlya_razdelenia";
        cin>>probel;
        proverka=probel;
        if (proverka==13||proverka==9)
            cout<<"ERROR";
        else{
            cout<<"vibirite_simvol_dlya_otstupa";
            cin>>otstup;
            proverka=otstup;

            if (proverka==13||proverka==9)
                cout<<"ERROR";
            else{

                {
                    for (size_t i = 0; i < bin_count; i++) {
                        if (bins[i] * 100 / count >= 100)
                            cout << "\n" << bins[i] * 100 / count << "%" << probel;
                        if (bins[i] * 100 / count >= 10)
                            cout << "\n" << otstup << bins[i] * 100 / count << "%" << probel;
                        else
                            cout << "\n" << otstup << otstup << bins[i] * 100 / count << "%"
                                    << probel;
                        for (size_t k = 0; k < bins[i]*kof; k++)
                            cout << el;

                    }
                }}}}
    cin>>el;
    return 0;
}