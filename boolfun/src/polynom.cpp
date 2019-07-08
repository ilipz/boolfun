#include "polynom.h"

<<<<<<< HEAD
using namespace std;

polynom::polynom(unsigned char n) {
	this->_length = pow(2,n);
	this->_coeff.reserve( static_cast<size_t>( this->length) );	 
}

bool polynom::set_coeff (std::vector<bvect32> arr) {
	if ( arr.size() >= pow(2,n) )
		return false;
	this->_values = arr;
	this->_length = pow(2,n);
	return true;
}

bvect32 polynom::get_coeff () {
	return this->_coeff;
} 

polynom::polynom (const ttable &t) {
	vector<unsigned char> result;
	vector<unsigned char> values = t.get_values();
	uint32_t limit = t.get_length() - 1;
	for (uint32_t i=0; i < limit; i++) {
		result[i] = 0;
		for (uint32_t j=0; j < limit; j++)
			result[i] += values[j] * pow(j,(limit - j));
	}
	this->_coeff = result;
}

uint32_t get_length () {
	return this->_length;
}
=======
namespace bf {

	polynom::polynom(unsigned char n, GF * _field) {
		this->_length = pow(2, n);
		this->_coeff.resize(static_cast<size_t>(this->_length));
	}

	void polynom::set_coeff(bvect32 n, bvect32 coeff) {
		/*if ( arr.size() >= pow(2,n) )
			return false; */
		this->_coeff[n] = coeff;
		//this->_length = pow(2,n);
		//return true;
	}

	unsigned char polynom::get_coeff(bvect32 n) {
		return this->_coeff[n];
	}

	polynom::polynom(const ttable& t) {

	}

	uint32_t polynom::get_length() {
		return this->_length;
	}

	GF * polynom::get_field() {
		return this->_field; 
	}
}
>>>>>>> c75867329af766ceae1ed2bd98a357b97a073d16
