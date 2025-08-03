#pragma once
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
#include<random>
#include<limits>
#include<regex>

namespace estd {

//Some useful mini-tools.
// 
 //template function max
 template<class _T>
 constexpr _T max(const _T& _a) {
	 return _a;
 }

 template<class _T>
 constexpr _T max(const _T& _a, const _T& _b) {
	 return (_a > _b) ? _a : _b;
 }

 template<class _T,class... _Args>
 constexpr _T max(const _T& _a, const _T& _b, const _Args&... _args) {
	 return max(max(_a, _b), _args...);
 }

 //template function min
 template<class _T>
 constexpr _T min(const _T& _a) {
	 return _a;
 }

 template<class _T>
 constexpr _T min(const _T& _a, const _T& _b) {
	 return (_a < _b) ? _a : _b;
 }

 template<class _T,class... Args>
 constexpr _T min(const _T& _a, const _T& _b,const Args&... _args) {
	 return min(min(_a, _b), _args...);
 }
 //Infinte number calculate.
 
 class infnum {
 public:
	 using byte_type = unsigned long long;
	 using number_type = std::vector<byte_type>;
	 using decimal_type = double;
	 constexpr static size_t byte_size = 
		 std::numeric_limits<byte_type>::digits10;
	                                  //+1 cause char + - cost a bit.
	 infnum(const number_type& _n = {},
		 const decimal_type& _d = 0,
		 bool _is = true);
	 explicit infnum(std::string _str);
	 infnum(const infnum&) = default;

	 inline size_t size() const;
	 std::string to_str() const;

	 infnum operator-() const;
	 inline void flip();

	 friend number_type str_to_vec(std::string);

	 friend infnum operator+(const infnum&, const infnum&);
	 friend infnum operator-(const infnum&, const infnum&);
	 friend infnum operator*(const infnum&, const infnum&);
	 friend infnum operator/(const infnum&, const infnum&);

	 friend std::istream& operator>>(std::istream&, infnum&);
	 friend std::ostream& operator<<(std::ostream&, const infnum&);

 private:
	 //helper function
	 //For examle:
	 //-4654132564152216518941252165846512654165265.456464652  return true
	 //5646gggohrggggg.114545454h return false
	 bool _is_num(const std::string _str);

	 bool _is_positive{ true };
	 number_type _val;          /*The number of vector
								 signed long long type usually 8 byte
								 If the number too long, to vector[1],val[1] so on.
	                                */

	 decimal_type _dec;         //Decimal,_dec < 1 
 };

 //Helper function
 infnum::number_type str_to_vec(std::string _str);

 //Calculation operator function
 infnum operator+(const infnum& _a, const infnum::byte_type& _b);
 infnum operator+(const infnum& _a, const infnum& _b);

 infnum operator-(const infnum& _a, const infnum::byte_type& _b);
 infnum operator-(const infnum& _a, const infnum& _b);

 infnum operator*(const infnum& _a, const infnum::byte_type& _b);
 infnum operator*(const infnum& _a, const infnum& _b);

 infnum operator/(const infnum& _a, const infnum::byte_type& _b);
 infnum operator/(const infnum& _a, const infnum& _b);

 // I/O operator function
 std::istream& operator>>(std::istream& _ist,infnum& _inf);
 inline std::ostream& operator<<(std::ostream& _ost, const infnum& _inf);

 //Easy random class
 template<typename _T>
 class rand {
 public:
	 static_assert(std::is_integral<_T>::value,
		 "rand: typename _T doesn't a integer type!");

	 explicit rand(_T _l, _T _h);

	 _T operator()();
 private:
	 std::default_random_engine _dre;
	 std::uniform_int_distribution<> _uid;
  };
}  //estd

#include "estd_math.cpp"