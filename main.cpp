  // This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
  #include <iostream>
  #include <fstream>
  #include <string>
  #include "card.h"
  #include "card_list.h"
  //Do not include set in this file

  using namespace std;

  int main(int argv, char** argc){
    if(argv < 3){
     std::cout<< "Please provide 2 file names" <<std::endl;
      return 1;
    }
    
    ifstream cardFile1 (argc[1]);
    ifstream cardFile2 (argc[2]);
    string line;

    if (cardFile1.fail() || cardFile2.fail() ){
     std::cout<< "Could not open file " << argc[2];
      return 1;
    }

    //Read each file

    CardList a;
    CardList b;
    
    while (getline (cardFile1, line) && (line.length() > 0)){
      string suit = line.substr(0,1);
      string value = line.substr(2);
      a.insert(suit,value);
    }
    cardFile1.close();


    while (getline (cardFile2, line) && (line.length() > 0)){
      string suit = line.substr(0,1);
      string value = line.substr(2);
      b.insert(suit,value);
    }
    cardFile2.close();
    
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


    return 0;
  }
