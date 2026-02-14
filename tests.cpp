#include <iostream> 
#include "card.h"
#include "card_list.h"
#include <string>

int main(){

    //tests an empty set 
    CardList empty;
    empty.print();
    std::cout << (empty.begin() == empty.end())<< std::endl;
    std::cout << (empty.begin() != empty.end())<< std::endl;
    std::cout << empty.contains(1) << std::endl << std::endl;
    for(auto it = empty.begin(); it != empty.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    for(auto it = empty.rbegin(); it != empty.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    

    //tests a set with a single element
    CardList single;
    single.insert("h","4");
    single.print();
    std::cout << single.contains(43) << std::endl;
    for(auto it = single.begin(); it != single.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    for(auto it = single.rbegin(); it != single.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    single.remove(43);
    std::cout << single.contains(43) << std::endl << std::endl;
    //tests a set with multiple elements 
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

    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    for(auto it = a.rbegin(); it != a.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    a.remove(4);
    a.remove(19);
    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    for(auto it = a.rbegin(); it != a.rend(); --it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << (a.begin() == it) << "  ";
    }
    std::cout << std::endl;
    for(auto it = a.rbegin(); it != a.rend(); --it){
        std::cout << (a.rbegin() == it) << "  ";
    }
    std::cout << std::endl;
    a.remove(31);
    a.remove(45);
    a.remove(0);
    std::cout << a.contains(4) << std::endl << std::endl;
    
    //CardList b;
    //CardList c;
    


    return 0;
}
