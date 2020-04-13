

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("add tow fathers to the same person") {
    Tree M("mika"); 
   CHECK( M.addFather("Avi") == string("mika"));
 CHECK( M.addMother("Sol"); == string("mika"));
CHECK( M.addFather("Ben") != string("mika"));

    /* Add more checks here */
}

TEST_CASE("add tow mothers to the same person") {
    Tree M("mika"); 
   CHECK( M.addFather("Avi") == string("mika"));
 CHECK( M.addFather("Sol"); == string("mika"));
CHECK( M.addMother("Or") != string("mika"));
}

TEST_CASE("add tow mothers to the same person") {
    Tree M("mika"); 
   CHECK( M.addFather("Avi") == string("mika"));
 CHECK( M.addFather("Sol"); == string("mika"));
CHECK( M.addMother("Or") != string("mika"));   
}

TEST_CASE("add grandmother") {
    Tree M("mika"); 
    Tree S("shir");
    Tree L("lior") ;
   CHECK( M.addFather(" Lior") == string("mika"));
 CHECK( M.addMother("Shir"); == string("mika"));
  CHECK( S.addMother(" Lee") == string("shir"));
 CHECK( S.addFather("Soso"); == string("shir"));
   CHECK( S.addFather("Papa") == string("Lior"));
 CHECK( S.addFather("Mama"); == string("Lior"));
   CHECK(M.relation("michal")==string("unrelated");
      CHECK(M.relation("Lior")==string("father");
       CHECK(M.relation("Shir")==string("mother");
        CHECK(M.relation("SOSO")==string("grandfather");
         CHECK(M.relation("lee")==string("grandmother");
            CHECK(M.relation("Papa")==string("grandfather");
         CHECK(M.relation("Mama")==string("grandmother");
         CHECK(M.find("mother")==string("shir"));
         CHECK(M.find("father")==string("lior"));
          CHECK(M.find("grandfather")==string("Soso"));
            CHECK(M.find("grandmather")==string("Mama"));
      CHECK(M.find("great-grandfather")==string("grandmather"));



 }

TEST_CASE("ERR")
{
      Tree M("mika"); 
     CHECK( M.addFather(" Lior") == string("mika"));
    CHECK( M.addFather("Shir"); == string("mika"));
    CHECK(M.relation("Tomer")==string("unrelated");
     CHECK(M.relation("michal")==string("unrelated");
      CHECK(M.relation("stav")==string("unrelated");
       CHECK(M.relation("kofiko")==string("unrelated");
        CHECK(M.relation("SOSO")==string("unrelated");

}




}