#ifndef __ESTD_MATH_CPP__
#define __ESTD_MATH_CPP__
#include"estd_math.h"

namespace estd {
	//Define class infnum function
	infnum::infnum(const number_type& _n,
		const decimal_type& _d,
		bool _is)
		:_val{ _n }, _is_positive{ _is }, _dec{ _d } {
	}

	infnum::infnum(std::string _str) 
	:_val{}, _dec{} {
		if (!infnum::_is_num(_str)) {
			this->~infnum();
			throw std::runtime_error{
				"infnum: Construction arg string patten failed!" };
		}

		
	}

	inline size_t infnum::size() const{
		return this->_val.size();
	}
	std::string infnum::to_str() const {
		std::ostringstream _ostr;
		for (size_t _n = 0; _n != this->size() - 1; ++_n)
			_ostr << this->_val.at(_n);
		return _ostr.str();
	}
	
	infnum infnum::operator-() const{
		infnum _res{ *this }; 
		_res._is_positive = false;
		return _res;
	}

	inline void infnum::flip() {
		this->_is_positive = !this->_is_positive;
	}

	bool infnum::_is_num(const std::string _str) {
		std::regex _r{ R"(^-?(\d+(.\d+)?)$)" };
		return std::regex_match(_str, _r);
	}
	
	//Define helper function
	infnum::number_type str_to_vec(std::string _str) {
		infnum res{};

		if (_str.at(0) == '-') {
			res = -res;
			_str = _str.substr(1, ios_base::end);
		}

		//Handle lead little number "byte".
		size_t le = _str.size() % res.byte_size; //Lead num size.
		if (le) {
			res._val.push_back(
				std::atoll(_str.substr(ios_base::beg, le).c_str())
			);
			_str = _str.substr(le, ios_base::end);
		}

		for (size_t _n = 1; _str.empty(); ++_n) {
			
		}
	}

	//Define calculation operator function
	//infnum operator+(const infnum& _a, const infnum::byte_type& _b) {

	/*

	infnum operator+(const infnum& _a, const infnum& _b) {
		infnum _res{};
		bool _is_one_by = false;

		_res._dec = _a._dec + _b._dec;
		if (_res._dec >= 1)
			_is_one_by = true;


	}
	*/
	//Define I/O operator function
	std::istream& operator>>(std::istream& _ist,infnum& _inf) {
		std::string _buff{};
		_ist >> _buff;
		_inf = infnum{ _buff };
		return _ist;
	}

	inline std::ostream& operator<<(std::ostream& _ost, const infnum& _inf) {
		return _ost << _inf.to_str();
	}


	//Define rand
	template<typename _T>
	rand<_T>::rand(_T _l, _T _h) :_uid{ _l,_h } {
	 }

	template<typename _T>
	_T rand<_T>::operator()() {
		return _uid(_dre);
	}
}

#endif /*__ESTD_MATH_CPP__*/
