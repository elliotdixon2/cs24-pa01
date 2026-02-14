// card.h
// Author: Your name
// All class declarations related to defining a single card go here
#include <string>
#include <iostream>

#ifndef CARD_H
#define CARD_H

struct Card{
    std::string suit;   
    std::string value;
    int suitedVal;
    Card(std::string s, std::string v);
    int computeSV();
    bool operator<(const Card& right) const;
    bool operator>(const Card& right) const;
    bool operator==(const Card& right) const;
};
std::ostream& operator<< (std::ostream& os, const Card& c);
#endif
