/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
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
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Fridge.h"
using namespace std;

namespace seneca{

    Food::Food() {}

    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN - 1);
        m_name[NAME_LEN - 1] = '\0';
        m_weight = wei;
    }
    const char* Food::name() const {
        return m_name;
    }
    int Food::weight() const {
        return m_weight;
    }
  
    Fridge::Fridge() : m_numFoods(0), m_model(nullptr)
    {
        m_model = new char[1];
        m_model[0] = '\0';
    }

    Fridge::Fridge(Food farr[], int nf, const char* mod) : m_numFoods(0), m_model(nullptr)
    {
        int i;
        if (mod) {
            m_model = new char[strlen(mod) + 1];
			strncpy(m_model, mod, strlen(mod));
			m_model[strlen(mod)] = '\0';
		}
        if (nf > 0) {
            m_numFoods = (nf < FRIDGE_CAP) ? nf : FRIDGE_CAP;
			for (i = 0; i < m_numFoods; i++) {
				m_foods[i] = farr[i];
			}
        }
    }

    Fridge::~Fridge() {
        delete[] m_model;
    }

    //rule of 3
    Fridge::Fridge(const Fridge& other) : m_numFoods(other.m_numFoods), m_model(nullptr)
	{
        if (other.m_model != nullptr) {
			m_model = new char[strlen(other.m_model) + 1];
			strcpy(m_model, other.m_model);
		}
		for (int i = 0; i < m_numFoods; i++) {
			m_foods[i] = other.m_foods[i];
		}
	}

    Fridge& Fridge::operator=(const Fridge& other)
	{
        int i;
        if (this != &other) {
            delete[] m_model;
            m_model = nullptr;

            m_numFoods = other.m_numFoods;
            if (other.m_model != nullptr) {
                m_model = new char[strlen(other.m_model) + 1];
                strcpy(m_model, other.m_model);
            }
            for (i = 0; i < m_numFoods; i++) {
                m_foods[i] = other.m_foods[i];
            }
        }
        return *this;
	}

    bool Fridge::addFood(const Food& f)
    {
        if (m_numFoods < FRIDGE_CAP) {
			m_foods[m_numFoods] = f;
			m_numFoods++;
			return true;
		}
        return false;
    }

    void Fridge::changeModel(const char* m)
    {
        if (m != nullptr && m[0] != '\0') {
            delete[] m_model;
            m_model = new char [strlen(m) +1];
			strncpy(m_model, m, strlen(m));
			m_model[strlen(m)] = '\0';
		}
    }

    bool Fridge::fullFridge() const
    {
        return m_numFoods == FRIDGE_CAP;
    }

    bool Fridge::findFood(const char* f) const
    {
        for (int i = 0; i < m_numFoods; i++) {
            if (strcmp(m_foods[i].name(), f) == 0) {
                return true;
            }
        }
        return false;
    }

    std::ostream& Fridge::display(std::ostream& os) const
    {
        if (m_model != nullptr && m_model[0] != '\0') {

            os << "Fridge Model: " << m_model << std::endl;
            os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << std::endl;
            
			if (m_numFoods > 0) {
                os << "List of Foods" << std::endl;
				for (int i = 0; i < m_numFoods; i++) {
					os << std::right << std::setw(20) << m_foods[i].name() << " | " << m_foods[i].weight() << std::endl;
				}
			}
            
		}
        return os;
    }

}
