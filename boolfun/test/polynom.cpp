#include <bitslib.h>
#include "polynom.h"
#include "ios.h"
#include "ttable.h"

namespace bf {
	//FIXME release NM functions
	polynom::polynom(GF *field) {
		this->_length = power2(static_cast<uint32_t>(field->get_order()));
		this->_coeff.resize(static_cast<size_t>(this->_length));
	}
	
	polynom::polynom(ttable &t, GF *field) {
		this->_length = t.get_length();
		this->_coeff.resize(static_cast<size_t>(this->_length));
		this->set_coeff(0, t.get_value(0));
		this->_field = field;
		vector<bvect32> values;
		const uint32_t tlen = tlen;

		for (uint32_t i = 0; i < tlen; i++)
			values.push_back(t.get_value(i));

		for (uint32_t coeffq = 0; coeffq < this->_length; coeffq++)
			for (uint32_t valuesq = 0; valuesq < tlen; valuesq++)
				this->set_coeff(coeffq,
				                (field->multiply(t.get_value(valuesq), field->power(valuesq, (tlen - valuesq - 1)))));
	}
	
	void polynom::set_coeff(uint32_t index, bvect32 coeff) {
		this->_coeff[index] = coeff;
	}

	bvect32 polynom::get_coeff(uint32_t index) {
		return this->_coeff[index];
	}

	uint32_t polynom::get_length() {
		return this->_length;
	}

	GF *polynom::get_field() {
		return this->_field;
	}

	bool polynom::set_from_string(const std::string &s) {
		// s must be low-cased and a[0] == %number%
		std::string in = s, s1;
		in = trim_all(in);
		stringstream ss;
		char c;
		ss.clear();
		ss << in;
		std::vector<string> words;

		while (getline(ss, s1, '+')) // get words between '+'
			words.push_back(s1);

		ss.clear();

		// Begin checking control (first) word {n:}
		ss << words[0];
		uint32_t t; //temp

		ss >> t; // read first word from stream


		if (t == 0)
			return false;
		this->_n = t;
		std::vector<uint32_t> coeffs(static_cast<size_t>(t));
		for (uint32_t i = 0; i < coeffs.size(); i++)
			coeffs[i] = 0;
		std::string tstr = words[0]; // temp string; get first word
		t = 0; // set vector<uint32_t> begin counter value
		//if ( tstr[tstr.length()-1] != ':' ) { // if wrote {n:C1x} in first word
		ss >> c; //skip ':'
		ss >> t;
		coeffs[0] = t;
		t = 1; // set begin counter to second element due to first word wrote wrong


		for (uint32_t i = t; i < words.size(); i++) {
			uint32_t degree = 0;
			ss.clear();

			tstr = words[i];
			ss << tstr;
			t = str2int(tstr);
			if (t == 0) // if no coeff
				t = 1; // coeff == 1
			ss >> c;
			if (c != 'x') {
				if (t == 1)
					return false;
				coeffs[0] ^= t;
				continue;
			}
			while (ss >> c)
				if (c == '^') {
					ss >>
					   tstr;
					if (tstr == "0") {
						degree = 0;
						break;
					}
					degree = str2int(tstr);
					break;
				}
			coeffs[degree] ^= t;
		}
		this->_coeff = coeffs;
		return true;		
	}
}