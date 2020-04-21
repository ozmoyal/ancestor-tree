#include <iostream>
#include <string>
#include "FamilyTree.hpp"

using namespace std;

namespace family{
node :: node(string n)
{
    this->name=n;
    this->father=nullptr;
    this->mother=nullptr;
}
Tree::Tree(string name){
  this->node=new node(name);
}

Tree &Tree::addFather(string name , string fatherName){
    Tree* p=add(this,name);
    if(p==nullptr) throw runtime_error("ERR  "+name+"dosen't exiest" );
    else if(p->father!=nullptr) throw runtime_error("ERR  "+name+"have a father" );
    else{
        p->father=new Tree(fatherName);
        p->count=p->father->count+1;
        return *this;
    } 
}

Tree &Tree::addMother(string name , string motherName){
      Tree* p=add(this,name);
    if(p==nullptr) throw runtime_error("ERR  "+name+"dosen't exiest" );
    else if(p->father!=nullptr) throw runtime_error("ERR  "+name+"have a mother" );
    else{
        p->mother=new Tree(motherName);
        p->count=p->mother->count+1;
        return *this;
    } 
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
Tree* Tree::add(Tree *cur,string name)
{
    if(cur->name==name) return cur;
        if(cur->mother!=nullptr) 
    {
        Tree *ans=add(cur->mother,name);
        if(ans!=nullptr) return ans;
    }
    if(cur->father!=nullptr) 
    {
        Tree *ans=add(cur->father,name);
        if(ans!=nullptr) return ans;
    }
    return nullptr;
    }

}

;