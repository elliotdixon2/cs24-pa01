// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h
#include "card.h"
#include "card_list.h"
#include <string>
#include <iostream>

void CardList::insert(std::string s, std::string v){
    Card newCard(s, v);

    if (!root){
        root = new CNode(newCard);
        return;
    }

    insert(newCard, root);
}
void CardList::insert(Card& newCard, CNode* cur){
    if (newCard > cur->storedCard){
        if (!cur->right){
            cur->right = new CNode(newCard);
            cur->right->parent = cur;
        } else {
            insert(newCard, cur->right);
        }
    } else if (newCard < cur->storedCard){
        if (!cur->left){
            cur->left = new CNode(newCard);
            cur->left->parent = cur;
        } else {
            insert(newCard, cur->left);
        }
    } else {
        return;
    }
}
void CardList::print(){
    if(!root) return;
    print(root);
}
void CardList::print(CNode* cur){
    if(!cur) return;
    print(cur->left);
    std::cout << cur->storedCard << std::endl;
    print(cur->right);
}

CardList::CNode* CardList::contains(int sv){
    if(!root) return nullptr;
    return contains(sv,root);
}
CardList::CNode* CardList::contains(int sv, CNode* cur){
    if(!cur) return nullptr;
    if(sv == cur->storedCard.suitedVal) return cur;
    else if(sv > cur->storedCard.suitedVal) return contains(sv,cur->right);
    else return contains(sv,cur->left);
}

void CardList::remove(int sv){
    CNode* n = contains(sv,root);
    if(!n){
        return;
    }
    if(!n->left && !n->right){
        if(!n->parent){
            root = nullptr;
        } else if (n->parent->left == n) {
            n->parent->left = nullptr;
        } else {
            n->parent->right = nullptr;
        }
        delete n;
    } else if(!n->left || !n->right){
        CNode* nChild;
        if(n->left){
            nChild = n->left;
        } else {
            nChild = n->right;
        }
        if(!n->parent){
            root = nChild; 
        } else if (n->parent->left == n){
            n->parent->left = nChild;
        } else {
            n->parent->right = nChild;
        }
        nChild->parent = n->parent;
        delete n;
    } else {
        CNode* nSuc = n->left;
        while(nSuc->right){
            nSuc = nSuc->right;
        }
        n->storedCard = nSuc->storedCard;
        if(nSuc->parent->left == nSuc){
            nSuc->parent->left = nSuc->left;
        } else {
            nSuc->parent->right = nSuc->left;
        }
        if(nSuc->left){
            nSuc->left->parent = nSuc->parent;
        }
        delete nSuc;
    }
}

bool CardList::iterator::operator==(const iterator& right) const {
    return cur == right.cur;
}
bool CardList::iterator::operator!=(const iterator& right) const {
    return cur != right.cur;
}   
CardList::iterator CardList::begin(){
    CNode* n = root;
    while(n && n->left){
        n = n->left;
    }
    return iterator(n);
}
CardList::iterator CardList::end(){
    return iterator();
}
CardList::iterator CardList::rbegin(){
    CNode* n = root;
    while(n && n->right){
        n = n->right;
    }
    return iterator(n);
}
CardList::iterator CardList::rend(){
    return iterator();
}
Card& CardList::iterator::operator*(){
    return cur->storedCard;
}
Card* CardList::iterator::operator->(){
    return &(cur->storedCard);
}

CardList::iterator& CardList::iterator::operator++(){
    if(!cur) return *this;
    if(cur->right){
        cur = cur->right;
        while(cur->left){
            cur = cur->left;
        }
    } else {
        CNode* par = cur->parent;
        while(par && par->left != cur){
            cur = par;
            par = par->parent;
        }
        cur = par;
    }
    return *this;
}
CardList::iterator& CardList::iterator::operator--(){
    if(!cur) return *this;
    if(cur->left){
        cur = cur->left;
        while(cur->right){
            cur = cur->right;
        }
    } else {
        CNode* par = cur->parent;
        while(par && par->right != cur){
            cur = par;
            par = par->parent;
        }
        cur = par;
    }
    return *this;
}