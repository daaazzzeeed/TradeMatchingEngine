//
//  main.cpp
//  TradeMathingEngine
//
//  Created by Дмитрий Петухов on 25.04.2018.
//  Copyright © 2018 petukhovd. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Agressor.h"
#include <sstream>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, const char * argv[]) {
    vector<Agressor> v;
    
    while (true) {
            std::string sText;
            cout << "enter query:" << endl;
            std::getline(std::cin, sText);
            
            std::vector<std::string> sWords = split(sText, ' ');
            Agressor agr;
            agr.traderIdentifier = sWords[0];
            agr.side = sWords[1];
            agr.quantity = stoi(sWords[2]);
            agr.price = stoi(sWords[3]);
            v.push_back(agr);
            
            for (vector<Agressor>::const_iterator i = v.begin(); i != v.end(); ++i)
                cout << *i << ' ';
    }
    
    
    return 0;
}
