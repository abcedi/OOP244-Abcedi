/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
// Abcedi Ilacas   2024-02-13
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstddef>
#include <iomanip>
#include "Guitar.h"
using namespace std;

namespace seneca{
    const char* GuitarStr::material() const {
        return m_material;
    }
    double GuitarStr::gauge() const {
        return m_gauge;
    }
    GuitarStr::GuitarStr() {};

    GuitarStr::GuitarStr(const char* ma, double ga) {
        if (ma) {
            strncpy(m_material, ma, MAT_LEN - 1);
            m_material[MAT_LEN - 1] = '\0';
        }
        else {
            m_material[0] = '\0';
        }
        
        m_gauge = ga;
    }

    Guitar::Guitar(const char* mod) : m_strings(nullptr), m_numStrings(0)
    {
        strncpy(m_model, mod ? mod : "Stratocaster", MODEL_LEN - 1);    
        m_model[MODEL_LEN - 1] = '\0';
    }

    Guitar::Guitar(GuitarStr strs[], size_t ns, const char* mod)
    {
        m_strings = new GuitarStr[ns];
        m_numStrings = ns;
        strncpy(m_model, mod ? mod : "Stratocaster", MODEL_LEN - 1);
		m_model[MODEL_LEN - 1] = '\0';
        for (size_t i = 0; i < ns; i++) {
			m_strings[i] = strs[i];
		}
    }

    Guitar::~Guitar()
    {
        delete[] m_strings;
    }

    Guitar::Guitar(const Guitar& other) : m_numStrings(other.m_numStrings)
    {
        m_strings = new GuitarStr[m_numStrings];
        strncpy(m_model, other.m_model, MODEL_LEN - 1);
        m_model[MODEL_LEN - 1] = '\0';

        for (size_t i = 0; i < m_numStrings; i++) {
			m_strings[i] = other.m_strings[i];
		}
    }

    Guitar& Guitar::operator=(const Guitar& other)
    {
        if (this != &other) {
			delete[] m_strings;
            m_strings = new GuitarStr[m_numStrings];
			m_numStrings = other.m_numStrings;

			strncpy(m_model, other.m_model, MODEL_LEN - 1);
            m_model[MODEL_LEN - 1] = '\0';
			for (size_t i = 0; i < m_numStrings; i++) {
            	m_strings[i] = other.m_strings[i]; 
            }
        }
        return *this;
    }

    bool Guitar::changeString(const GuitarStr& gs, size_t sn)
    {
        if (sn < m_numStrings) {
			m_strings[sn] = gs;
			return true;
		}
        return false;
    }

    void Guitar::reString(GuitarStr strs[], size_t ns)
    {
        delete[] m_strings;
		m_strings = new GuitarStr[ns];
		m_numStrings = ns;
		for (size_t i = 0; i < ns; i++) {
        	m_strings[i] = strs[i];
        }
    }

    void Guitar::deString()
    {
        delete[] m_strings;
        m_strings = nullptr;
        m_numStrings = 0;

    }

    bool Guitar::strung() const
    {
        return m_numStrings > 0;
    }

    bool Guitar::matchGauge(double ga) const
    {
        for (size_t i = 0; i < m_numStrings; i++) {
            if (m_strings[i].gauge() == ga) {
				return true;
			}
        }
        return false;
    }

    std::ostream& Guitar::display(std::ostream& os) const
    {
        if (strung()) {
			os << "Guitar Model: " << m_model << std::endl;
            os << "Strings: " << m_numStrings << std::endl;
            for (size_t i = 0; i < m_numStrings; i++) {
				os << "#" << (i + 1) << std::setw(MAT_LEN) << std::right<< m_strings[i].material() << " | " << std::fixed << std::setprecision(1) << m_strings[i].gauge() << std::endl;
			}
		}
        else {
			os << "***Empty Guitar***" << std::endl;
		}
        return os;
    }



} // namespace seneca
