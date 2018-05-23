#include <iostream>
#include "Temperature.h"
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    size_t count;
    char el, probel, otstup;
    int proverka;
    double kof;
    cout<<"\n chislo el ";
    cin >> count;
    vector<Temperature> xs(count);
    vector<double> xsk (count);
    cout<<"\n vvedite  "<<count<<" elementov ";
    for (size_t i = 0; i < count; i++) {
        cin >> xs[i];
        if (cin.fail() ){return -1;}
        xsk[i]=convert(xs[i],'K');

    }
    size_t bin_count;
    cout<<"\n chislo korzin ";
    cin >> bin_count;
    double min = xsk[0], max = xsk[0];
    for ( double x:xsk) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
    vector<size_t> bins(bin_count, 0);
    for (double x:xsk) {
        size_t index = (x - min) / (max - min) * bin_count;
        if (x == max) {
            index--;
        }
        bins[index]++;
    }
    kof=1;
    if (max>(352)){
        kof=(1-(max-352)/max);}
    cout<<kof<<" \n";
    cout<<"vibirite_simvol_dlya_elementa";
    cin>>el;
    proverka=el;
    if (proverka==13||proverka==9)
        cout<<"ERROR";
    else{
        cout<<"vibirite_simvol_dlya_razdelenia";
        cin>>probel;
        proverka=probel;
        if (proverka==13||proverka==9)
            cout<<"ERROR";
        else {
            cout << "vibirite_simvol_dlya_otstupa";
            cin >> otstup;
            proverka = otstup;

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
                        for (size_t k = 0; k < bins[i]; k++)
                            cout << el;

                    }
                }}}}

    cin>>el;
    return 0;
}
