//
//  Agressor.h
//  TradeMathingEngine
//
//  Created by Дмитрий Петухов on 25.04.2018.
//  Copyright © 2018 petukhovd. All rights reserved.
//

#ifndef Agressor_h
#define Agressor_h

#include <string>

using namespace std;

class Agressor{
public:
    /*const char**/ string traderIdentifier;
    /*const char**/ string side;
    int quantity;
    int price;
    
    void display(){
        cout << traderIdentifier << " " << side << " " << quantity << " " << price << endl;
    }
    explicit Agressor(){
        
    }
    ~Agressor(){
        
    }
    friend ostream &operator<<(ostream& stream, const Agressor& item);
    
};

ostream &operator<<(ostream& stream, const Agressor& item) {
    stream << item.traderIdentifier << " " << item.side << " " << item.quantity << " " << item.price << endl;
    return stream;
}

#endif /* Agressor_h */
