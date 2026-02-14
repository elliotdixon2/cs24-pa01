#include <iostream> 
#include "card.h"
#include "card_list.h"
#include <string>

void playGame(CardList& a, CardList& b); 

int main(){

    //EMPTY SET TESTS =====================
    //Print
    //Begin/end comparison using == and != 
    //Contains
    std::cout << "Empty set tests:" << std::endl;
    CardList empty;
    empty.print();
    std::cout << (empty.begin() == empty.end())<< std::endl;
    std::cout << (empty.begin() != empty.end())<< std::endl;
    std::cout << empty.contains(1) << std::endl << std::endl;
    //Forwards iterator
    for(auto it = empty.begin(); it != empty.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    //Backwards iterator
    for(auto it = empty.rbegin(); it != empty.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    




    //SINGLE NODE SET TESTS =================
    //Insertion
    //Print
    //Contains for value that does/doesn't exist in set
    std::cout << "Single node set tests:" << std::endl;
    CardList single;
    single.insert("h","4");
    single.print();
    std::cout << single.contains(43) << std::endl;
    std::cout << single.contains(40) << std::endl;
    //Forwards iterator
    for(auto it = single.begin(); it != single.end(); ++it){
        std::cout << *it << "  ";
    }
    //Backwards iterator
    std::cout << std::endl;
    for(auto it = single.rbegin(); it != single.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    //Removal of single node and then contains on node value
    single.remove(43);
    std::cout << single.contains(43) << std::endl << std::endl;





    //Tests a set with multiple elements 
    //Insertion of 5 elements
    //Print
    //Contains of 4 elements that exist in set, one that does not 
    std::cout << "multiple node set tests:" << std::endl;
    CardList a;
    a.insert("c","4");
    a.insert("s","5");
    a.insert("h","6");
    a.insert("d","6");
    a.insert("d","8");
    a.print();
    std::cout << a.contains(4) << std::endl;
    std::cout << a.contains(19) << std::endl;
    std::cout << a.contains(31) << std::endl;
    std::cout << a.contains(45) << std::endl;
    std::cout << a.contains(0) << std::endl;
    //Forwards iterator
    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    //Backwards iterator
    for(auto it = a.rbegin(); it != a.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    //Removal of two elements from the set
    a.remove(4);
    a.remove(19);
    //Forwards iterator post removal of 2 nodes
    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    //Backwards iterator post removal of 2 nodes
    for(auto it = a.rbegin(); it != a.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    //Forwards iterator to compare iterator == to the beginning of the BST
    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << (a.begin() == it) << "  ";
    }
    std::cout << std::endl;
    //Backwards iterator to compare iterator == to the beginning of the BST
    for(auto it = a.rbegin(); it != a.rend(); --it){
        std::cout << (a.rbegin() == it) << "  ";
    }
    std::cout << std::endl << std:: endl;
    




    //Test cases for the playGame function ======================
    std::cout << "Test cases for the playGame function:" << std::endl;
    //Both players with common cards
    CardList p1,p2;
    p1.insert("c","4");
    p2.insert("c","4");
    playGame(p1,p2);
    std::cout << std::endl;
    //One empty hand
    CardList p3,p4;
    p3.insert("c","4");
    playGame(p3,p4);
    std::cout << std::endl;

    //No common cards
    CardList p5,p6;
    p5.insert("c","4");
    p6.insert("c","5");
    playGame(p5,p6);
    return 0;
}

void playGame(CardList& a, CardList& b){
    bool aTurn = true;
    while(a.begin() != a.end() && b.begin() != b.end()){
      if(aTurn){
        auto itA = a.begin();
        while(itA != a.end()){
          int itValue = itA->suitedVal;
          auto location = b.contains(itValue);
          if(location){
           std::cout<< "Alice picked matching card " << itA->suit << " " << itA->value <<std::endl;
            a.remove(itValue);
            b.remove(itValue);
            break;
          }
          ++itA;
        }
        if(itA == a.end()) break;
        aTurn = false;
      } else {
        auto itB = b.rbegin();
        while(itB != b.rend()){
          int itValue = itB->suitedVal;
          auto location = a.contains(itValue);
          if(location){
           std::cout<< "Bob picked matching card " << itB->suit << " " << itB->value <<std::endl;
            a.remove(itValue);
            b.remove(itValue);
            break;
          }
          --itB;
        }
        if(itB == b.rend()) break;
        aTurn = true;
      }
    }
    std::cout <<std::endl << "Alice's cards:" <<std::endl;
    a.print();
    std::cout <<std::endl << "Bob's cards:" <<std::endl;
    b.print();
}