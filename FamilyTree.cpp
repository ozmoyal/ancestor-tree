#include <iostream>
#include <string>
#include "FamilyTree.hpp"

using namespace std;

namespace family{

Tree::Tree(string name){
  this->name=name;
  this->father=nullptr;
  this->mother=nullptr;
}

Tree &Tree::addFather(string name , string fatherName){
    Tree* p=add(this,name);
    if(p==nullptr) throw runtime_error("ERR  "+name+"dosen't exiest" );
    else if(p->father!=nullptr) throw runtime_error("ERR  "+name+"have a father" );
    else{
        p->father=new Tree(fatherName);
        p->count=p->father->count+1;
        p->gander="male";
        return *this;
    } 
}

Tree &Tree::addMother(string name , string motherName){
      Tree* p=Find(this,name);
    if(p==nullptr) throw runtime_error("ERR  "+name+"dosen't exiest" );
    else if(p->father!=nullptr) throw runtime_error("ERR  "+name+"have a mother" );
    else{
        p->mother=new Tree(motherName);
        p->count=p->mother->count+1;
        p->gander="female";
        return *this;
    } 
}

void Tree::display(){
    Tree* p=this;
    print(p);


}
string Tree::relation(string name){
    Tree *p =Find(this,name);
    if(p==nullptr) return "unrelated";
    if((p->count)==1)
    {
        if(p->gander=="male") return "father";
        else return "mather";
    }
    if((p->count==2))
    {
         if(p->gander=="male") return "grandfather";
        else return "grandmather";
    }
    int i=p->count;
    string ans="";
    while(i>=0) 
    {
        ans=ans+"grand- ";
        i--;
    }
       if(p->gander=="male") ans=ans+ "father";
        else return ans=ans+"mather";
        return ans;
}


string Tree::find(string name){
 
}

void Tree::remove(string name){

}
Tree* Tree::Find(Tree *cur,string name)
{
    if(cur->name==name) return cur;
        if(cur->mother!=nullptr) 
    {
        Tree *ans=Find(cur->mother,name);
        if(ans!=nullptr) return ans;
    }
    if(cur->father!=nullptr) 
    {
        Tree *ans=Find(cur->father,name);
        if(ans!=nullptr) return ans;
    }
    return nullptr;
    }


void Tree::print(Tree *cur)
{
    if(cur==nullptr) return;
    print(cur->father);
    print(cur->mother);
    printf(cur->name);
}
}
;