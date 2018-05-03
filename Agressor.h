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
#include <vector>

using namespace std;

class Agressor{
public:
    /*const char**/ string traderIdentifier;
    /*const char**/ string side;
    int quantity;
    int price;
    vector<Agressor> v;
    
    void display(){
        cout << traderIdentifier << " " << side << " " << quantity << " " << price << endl;
    }
    explicit Agressor(){
        
    }
    ~Agressor(){
        
    }
    friend ostream &operator<<(ostream& stream, const Agressor& item);
    const friend bool operator > (const Agressor &a1, const Agressor &a2);

   // const friend bool operator == (const Agressor &a1, const Agressor &a2);
    
    /* vector<Agressor>& operator[](int i ){
        return v[i];
    }*/

    
};


ostream &operator<<(ostream& stream, const Agressor& item) {
    string side = "";
    if(item.side == "B"){
        side = '+';
    }else{
        if(item.side == "S"){
            side = "-";
        }
    }

    stream << item.traderIdentifier << side << item.quantity << "@" << item.price << "\n";
    return stream;
}

const bool operator == (const Agressor &a1, const Agressor &a2){
    bool isEqual = false;
    if((a1.price*a1.quantity == a2.price*a2.quantity) && (a1.traderIdentifier == a2.traderIdentifier) && (a1.side == a2.side)){
        isEqual = true;
    }
    return(isEqual);
}


const bool operator > (const Agressor &a1, const Agressor &a2){
    bool isGreater = false;
    if(a1.price*a1.quantity > a2.price*a2.quantity){
        isGreater = true;
    }
    return(isGreater);
}



#endif /* Agressor_h */
