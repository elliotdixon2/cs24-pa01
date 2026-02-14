// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include <string>
#include "card.h"
#include <iostream>

Card::Card(std::string s, std::string v){
    suit = s;
    value = v;
    suitedVal = computeSV();
}
int Card::computeSV(){
    int numValue;
    if(value == "a") numValue = 1;
    else if(value == "j") numValue = 11;
    else if(value == "q") numValue = 12;
    else if(value == "k") numValue = 13;
    else numValue = stoi(value);
    
    if(suit == "c") return numValue;
    else if(suit == "d") return numValue + 13;
    else if(suit == "s") return numValue + 26;
    else return numValue + 39;
}

bool Card::operator<(const Card& right) const {
        return suitedVal < right.suitedVal;
}
bool Card::operator>(const Card& right) const {
        return suitedVal > right.suitedVal;
}
bool Card::operator==(const Card& right) const {
        return suitedVal == right.suitedVal;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.suit << " " << card.value;
    return os;
}