#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "bitslib.h"
#include "GF.h"

// Max polynom length 2^n (n <= 32)
// Max var quanity n (n <= 32)

namespace bf
{
    class ttable;
    class ttable64;

    class polynom
    { // over field type

    public:
        polynom(GF *field);
        polynom(ttable &t, GF *field);
        void set_coeff(uint32_t index, bvect32 coeff);
        bvect32 get_coeff(uint32_t index);
        uint32_t get_length();
        GF *get_field();
        bool set_from_string(const std::string &s);

    private:
        std::vector<bvect32> _coeff;
        uint32_t _length;
        GF *_field;

    };

    class polynom64
    { // over field type

    public:
        polynom64(GF *field);
        polynom64(ttable &t, GF *field);
        void set_coeff(uint64_t index, bvect64 coeff);
        bvect64 get_coeff(uint64_t index);
        uint64_t get_length();
        GF *get_field();

    private:
        std::vector<bvect64> _coeff;
        uint64_t _length;
        GF *_field;
    };
}