// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  set<Card> a;
  set<Card> b;
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    string suit = line.substr(0,1);
    string value = line.substr(2);
    a.insert(Card(suit,value));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    string suit = line.substr(0,1);
    string value = line.substr(2);
    b.insert(Card(suit,value));
  }
  cardFile2.close();

  
  
  bool aTurn = true;
  while (!a.empty() && !b.empty()){
    auto itA = a.begin();
    auto itB = b.rbegin();
    if(aTurn){
      while(itA != a.end()){
        auto locate = b.find(*itA);
        if(locate != b.end()){
          cout << "Alice picked matching card " << itA->suit << " " << itA->value << endl;
          itA = a.erase(itA);
          b.erase(locate);
          itB = b.rbegin();
          aTurn = false;
          break;
        }
        ++itA;
      }
      if(itA == a.end()) break;
    } else {
      while(itB != b.rend()){
        auto locate = a.find(*itB);
        if(locate != a.end()){
          cout << "Bob picked matching card " << itB->suit << " " << itB->value << endl;
          b.erase(prev(itB.base()));
          a.erase(locate);
          itA = a.begin();
          aTurn = true;
          break;
        } 
          ++itB;
      }
      if (itB == b.rend()) break;
    }
  }
  cout << endl << "Alice's cards:" << endl;
  for (Card ca : a){
    cout << ca << endl;
  }
  cout << endl <<  "Bob's cards:" << endl;
  for (Card cb : b){
    cout << cb << endl;
  }
  return 0;
}
