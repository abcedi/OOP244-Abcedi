/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  guitar.h
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
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>
#include <cstddef>

namespace seneca {

    const int MAT_LEN = 10;
    const int MODEL_LEN = 20;

    class GuitarStr {
        char m_material[MAT_LEN]{};
        double m_gauge{};
    public:
        const char* material()const;
        double gauge()const;
        GuitarStr();
        GuitarStr(const char* ma, double ga);
    };

    class Guitar {
    private:
        GuitarStr* m_strings{};
        size_t m_numStrings{};
        char m_model[MODEL_LEN]{};


    public:
        Guitar(const char* mod = "Stratocaster");
        Guitar(GuitarStr strs[], size_t ns, const char* mod);
        ~Guitar(); // destructor

        Guitar(const Guitar& other);
        Guitar& operator=(const Guitar& other);

        bool changeString(const GuitarStr& gs, size_t sn);
        void reString(GuitarStr strs[], size_t ns);
        void deString();

        bool strung()const;
        bool matchGauge(double ga) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };
}

#endif // !SENECA_GUITAR_H
