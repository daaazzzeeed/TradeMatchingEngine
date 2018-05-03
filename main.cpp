//
//  main.cpp
//  TradeMathingEngine
//
//  Created by Дмитрий Петухов on 25.04.2018.
//  Copyright © 2018 petukhovd. All rights reserved.
//

#include <iostream>
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

bool equal_comp(const Agressor& a1, const Agressor& a2){
    if((a1.price*a1.quantity == a2.price*a2.quantity) && (a1.traderIdentifier == a2.traderIdentifier) && (a1.side == a2.side)){
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    Agressor agr;
    while (true) {
            std::string sText;
            cout << "enter query:" << endl;
            std::getline(std::cin, sText);
        if(sText == "q"){
            cout << "Program terminated by user" << endl;
            break;
        }else{
            std::vector<std::string> sWords = split(sText, ' ');
            agr.traderIdentifier = sWords[0];
            agr.side = sWords[1];
            agr.quantity = stoi(sWords[2]);
            agr.price = stoi(sWords[3]);
            agr.v.push_back(agr);
       
            vector<Agressor>::iterator it;
            sort(agr.v.begin(), agr.v.end(), greater<Agressor>());
            //unique(agr.v.begin(), agr.v.end(), equal_comp);
            for (vector<Agressor>::const_iterator i = agr.v.begin(); i != agr.v.end(); ++i)
                cout << *i << ' ';
         
    }
    }
    cout << "here we go..." << endl;
    vector<Agressor>::iterator it;
    sort(agr.v.begin(), agr.v.end(), greater<Agressor>());
    //it = unique(agr.v.begin(),agr.v.end(), equal_comp);
    //agr.v.resize( distance(agr.v.begin(),it) );
    agr.v.erase(unique(agr.v.begin(),agr.v.end(), equal_comp), agr.v.end());
    
    copy(agr.v.begin(), agr.v.end(), ostream_iterator<Agressor>(cout, "\n"));

    
    
    return 0;
}
