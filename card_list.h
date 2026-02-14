// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand
#include <string>
#include "card.h"
#ifndef CARD_LIST_H
#define CARD_LIST_H

//to create:
//insert, remove, contains
//print method
//begin,end,rbegin,rend
//operator++, operator--

class CardList{
private:
    struct CNode{
        Card storedCard;
        CNode* parent;
        CNode* left;
        CNode* right;
        CNode(const Card& c): storedCard(c), parent(nullptr), left(nullptr), right(nullptr){}
    };
    CNode* root;
public:
    class iterator{
        private:
            CNode* cur;
        public:
            iterator(): cur(nullptr){}
            iterator(CNode* n): cur(n){}
            bool operator==(const iterator& right) const;
            bool operator!=(const iterator& right) const;
            iterator& operator++();
            iterator& operator--();
            Card& operator*();
            Card* operator->();
    };
    CardList() : root(nullptr) {}
    void insert(std::string s, std::string v);
    void insert(Card& newCard, CNode* cur);
    void remove(int sv);
    CNode* contains(int sv, CNode* cur);
    CNode* contains(int sv);
    void print();
    void print(CNode* cur);
    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();
};
#endif
