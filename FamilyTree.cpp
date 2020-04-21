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
    Tree* p=Find(this,name);
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
    string ans="";
    int i=p->count;
    while(i>=2) 
    {
        ans=ans+"great- ";
        i--;
    }
       if(p->gander=="male") ans=ans+ "grandfather";
        else return ans=ans+"grandmather";
        return ans;
}


string Tree::find(string relation){
    if(relation.compare("mother")==0)
    {
    if(this->mother==nullptr)throw runtime_error("ERR  "+relation+"dosen't exiest" ); 
    else return this->mother->name;
    }
      if(relation.compare("father")==0)
    {
    if(this->father==nullptr)throw runtime_error("ERR  "+relation+"dosen't exiest" ); 
    else return this->father->name;
    }
  
    
    
    

    )

    if(relation=="father") return this->mother->name;

 
}

void Tree::remove(string name){
    Tree* p=Find(this,name);
    helpRemove(p);

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

void Tree::helpRemove(Tree *cur)
{
    if(cur==nullptr) return ;
    helpRemove(cur->father);
    helpRemove(cur->mother);
    cur=nullptr;
}
void Tree::print(Tree *cur)
{
    if(cur==nullptr) return;
    print(cur->father);
    print(cur->mother);
    printf("--->,%s",cur->name);
}
}
;