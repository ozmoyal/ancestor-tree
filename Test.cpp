

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;

TEST_CASE("add father") {
   Tree M("mika");
   M.addFather("mika","Yitzak").addFather("Yitzak","Israel").addFather("Israel","Yaakov");
      CHECK((tree.head->father->name).compare("Yitzak") == 0);
    CHECK((tree.head->father->father->name).compare("Israel") == 0);
   CHECK((tree.head->father->father->father->name).compare("Yaakov") == 0);

}
TEST_CASE("add father") {
   Tree M("mika");
   M.addMother("mika","Stella").addFather("Stella","Michal").addFather("Michal","Tehila");
    CHECK((tree.head->mother->name).compare("Stella") == 0);
    CHECK((tree.head->mothe->mothe->name).compare("Michal") == 0);
   CHECK((tree.head->mothe->mothe->mothe->name).compare("Tehila") == 0);

}

TEST_CASE("check find")
{
    Tree T("Mika");
    T.addFather("Mika", "Yitzak").addFather("Yitzak", "Israel")
     .addFather("Israel", "Avraham") .addMother("Israel", "Pnina")	    
     .addMother("Mika", "Stella").addMother("Stella","Michal").addFather("Stella","Yaakov") 
     .addMother("Yitzak","Tamar").addFather("Tamar","Meir").addMother("Tamar","Hana");
	T.display();
    CHECK(T.find("me") == string("Mika"));
    CHECK(T.find("mother") == string("Stella"));
    CHECK(T.find("father") == string("Yitzak"));
    CHECK(T.find("grandfather") == string("Israel"));
    CHECK(T.find("grandfather") == string("Yaakov"));
    CHECK(T.find("grandmother") == string("Tamar"));
    CHECK(T.find("grandmother") == string("Michal"));
    CHECK(T.find("great-grandmother") == string("Pnina"));
    CHECK(T.find("great-grandmother") == string("Hana"));
    CHECK(T.find("great-grandfather") ==string( "Meir"));
    CHECK(T.find("great-grandfather") == string("Avraham"));	
}

TEST_CASE("check relation")
{
    Tree T("Mika");
    T.addFather("Mika", "Yitzak").addFather("Yitzak", "Israel")
     .addFather("Israel", "Avraham") .addMother("Israel", "Pnina")	    
     .addMother("Mika", "Stella").addMother("Stella","Michal").addFather("Stella","Yaakov") 
     .addMother("Yitzak","Tamar").addFather("Tamar","Meir").addMother("Tamar","Hana");
	T.display();
     CHECK(T.relation("Mika") == string("me"));
    CHECK(T.relation("Yitzak") == string("father"));
    CHECK(T.relation("Israel") == string("grandfather"));
    CHECK(T.relation("Yaakov") == string("grandfather"));
    CHECK(T.relation("Tamar") == string("grandmother"));
    CHECK(T.relation("Michal") == string("grandmother"));
    CHECK(T.relation("Pnina") == string("great-grandmother"));
    CHECK(T.relation("Hana") == string("great-grandmother"));
    CHECK(T.relation("Meir") ==string( "great-grandfather"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    //27
}	

TEST_CASE("Tree 1")
{
  Tree T("Stav");
  T.addMother("Stav","Tal").addFather("Stav","Yitzak");
  T.addMother("Tal","Michal").addMother("Michal","Tehila").addMother("Tehila","Yaffa").addFather("Tehila","Yehoda");
  T.addFather("Michal","Meir").addMother("Meir","Tamar").addFather("Meir","Yossef");
  T.addFather("Tal","Avraham").addFather("Avraham","Shoshana").addFather("Avraham","Michael").addMother("Shoshana","Ester");
  T.addMother("Yitzak","Bat-Zehav").addFather("Yitzak","Israel").addFather("Israel","David").addMother("Israel","Pnina");
  T.display();
     CHECK(T.find("me") == string("Stav"));
    CHECK(T.find("mother") == string("Tal"));
    CHECK(T.find("father") == string("Yitzak"));
    CHECK(T.find("grandfather") == string("Israel"));
    CHECK(T.find("grandfather") == string("Avraham"));
    CHECK(T.find("grandmother") == string("Bat-Zehav"));
    CHECK(T.find("grandmother") == string("Michal"));
    CHECK(T.find("great-grandmother") == string("Pnina"));
    CHECK(T.find("great-grandmother") == string("Tehila"));
       CHECK(T.find("great-grandmother") == string("Shoshana"));
    CHECK(T.find("great-grandfather") ==string( "Meir"));
    CHECK(T.find("great-grandfather") == string("Michael"));	
        CHECK(T.find("great-great-grandmother") == string("Ester"));	
     CHECK(T.find("great-great-grandmother") == string("Tamar"));	
  CHECK(T.find("great-great-grandmother") == string("Yaffa"));
   CHECK(T.find("great-great-grandfather") == string("Yehoda"));	
    CHECK(T.find("great-great-grandfather") == string("Yossef"));	
      CHECK(T.find("great-great-great-grandfather") == string("ERR"));	


     CHECK(T.relation("Stav") == string("me"));
    CHECK(T.relation("Tal") == string("mother"));
    CHECK(T.relation("Yitzak") == string("father"));
    CHECK(T.relation("Israel") == string("grandfather"));
    CHECK(T.relation("Avraham") == string("grandfather"));
    CHECK(T.relation("Bat-Zehav") == string("grandmother"));
    CHECK(T.relation("Michal") == string("grandmother"));
    CHECK(T.relation("Pnina") == string("great-grandmother"));
    CHECK(T.relation("Tehila") == string("great-grandmother"));
       CHECK(T.relation("Shoshana") == string("great-grandmother"));
    CHECK(T.relation("Meir") ==string("great-grandfather"));
    CHECK(T.relation("Michael") == string("great-grandfather"));	
        CHECK(T.relation("Ester") == string("great-great-grandmother"));	
     CHECK(T.relation("Tamar") == string("great-great-grandmother"));	
  CHECK(T.relation("Yaffa") == string("great-great-grandmother"));
   CHECK(T.relation("Yehoda") == string("great-great-grandfather"));	
    CHECK(T.relation("Yossef") == string("great-great-grandfather"));
      CHECK(T.relation("Noam") == string("unrelated"));	
    CHECK(T.relation("Shirel") == string("unrelated"));
//64
}

TEST_CASE("Tree 2")
{
  Tree T("Noam");
  T.addMother("Noam","Tal").addMother("Tal","Mika").addFather("Tal","Tomer");
  T.addFather("Noam","Bar").addMother("Bar","Stav").addFather("Bar","Ronen");
    T.display();
    CHECK(T.find("me") == string("Noam"));
    CHECK(T.find("mother") == string("Tal"));
    CHECK(T.find("father") == string("Bar"));
     CHECK(T.find("grandfather") == string("Tomer"));
    CHECK(T.find("grandfather") == string("Ronen"));
    CHECK(T.find("grandmother") == string("Mika"));
    CHECK(T.find("grandmother") == string("Stav"));

     CHECK(T.relation("Noam") == string("me"));
    CHECK(T.relation("Tal") == string("mother"));
    CHECK(T.relation("Bar") == string("father"));
    CHECK(T.relation("Tomer") == string("grandfather"));
    CHECK(T.relation("Ronen") == string("grandfather"));
    CHECK(T.relation("Mika") == string("grandmother"));
    CHECK(T.relation("Stav") == string("grandmother"));
       CHECK(T.relation("Kim") == string("unrelated"));

       T.remove("Bar");
       CHECK(T.relation("Bar") == string("unrelated"));
    CHECK(T.relation("Stav") == string("unrelated"));
    CHECK(T.relation("Ronen") == string("unrelated"));


}//79


TEST_CASE("Tree 3")
{
   Tree T("Ron");
  T.addMother("Ron","Rotem").addMother("Rotem","Ronit").addFather("Rotem","Matan");
  T.addFather("Noam","Moshe").addMother("Moshe","Hen").addFather("Moshe","Ronen");
    T.display();
    CHECK(T.find("me") == string("Ron"));
    CHECK(T.find("mother") == string("Rotem"));
    CHECK(T.find("father") == string("Moshe"));
     CHECK(T.find("grandfather") == string("Matan"));
    CHECK(T.find("grandfather") == string("Ronen"));
    CHECK(T.find("grandmother") == string("Ronit"));
    CHECK(T.find("grandmother") == string("Hen"));
    
     CHECK(T.relation("Ron") == string("me"));
    CHECK(T.relation("Rotem") == string("mother"));
    CHECK(T.relation("Moshe") == string("father"));
    CHECK(T.relation("Matan") == string("grandfather"));
    CHECK(T.relation("Ronen") == string("grandfather"));
    CHECK(T.relation("Hen") == string("grandmother"));
    CHECK(T.relation("Ronit") == string("grandmother"));
       CHECK(T.relation("pol") == string("unrelated"));
       T.remove("Matan");
          CHECK(T.relation("Matan") == string("unrelated"));
          T.addFather("Rotem","Oz");
           CHECK(T.find("grandfather") == string("Oz"));
            CHECK(T.relation("Oz") == string("grandfather"));
            T.remove("Ronen");
              CHECK(T.relation("Matan") == string("unrelated"));
              T.addFather("Moshe","Niv");
                  CHECK(T.relation("Niv") == string("grandfather"));




      


    

