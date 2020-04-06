#include <iostream>
#include <string>
#include "FamilyTree.hpp"

using namespace std;

namespace family{

Tree::Tree(string name){
    this->name = name;
    this->count =0;
    this->father = NULL;
    this->mother = NULL;
}

Tree &Tree::addFather(string name , string relation){
    return *this;
}

Tree &Tree::addMother(string name , string relation){
    return *this;
}

void Tree::display(){

}
string Tree::relation(string relation){
    string ans = "";
    return ans;
}
string Tree::find(string relation){
    string ans = "";
    return ans;
}

void Tree::remove(string name){

}

};