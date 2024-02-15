/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Abcedi Ilacas   2024/02/10      
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>

namespace seneca{

   const int NAME_LEN = 10;
   const int FRIDGE_CAP = 3; // maximum number of food items in the fridge
   const int MODEL_LEN = 20;

   class Food {
      char m_name[NAME_LEN]{};
      int m_weight{};
   public:
       Food();
       Food(const char* nm, int wei);
       const char* name()const;
       int weight()const;
   };

   class Fridge {
   private:
	  Food m_foods[FRIDGE_CAP];
	  int m_numFoods;
      char* m_model;
   public:
       Fridge();
       Fridge(Food farr[], int nf, const char* mod = "Ice Age");
       ~Fridge();

       Fridge(const Fridge& other);
       Fridge& operator=(const Fridge& other);

       bool addFood(const Food& f);
       void changeModel(const char* m);
       bool fullFridge()const;
       bool findFood(const char* f)const;
       std::ostream& display(std::ostream& os = std::cout)const;
    };

}
#endif // !SENECA_FRIDGE_H
