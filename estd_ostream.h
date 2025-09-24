/*
*   这是个扩展std标准库中的精简输出库
*	编写 : yzq
*	版权所有
*
*	This is a output sub-library of extend stand library.
*	Writer : yzq
*   All right reserved.
*
*/
#pragma once

/*
 *  If user's platform have __builtin_* function, 
 *  platform will define @__ESTD__HAS_BUILTIN_FUNCTION__.
 *  Else don't define it, and this file won't define @estd::ostream.
*/
#ifdef __has_builtin

namespace estd {
	/*
	* class @endl_type
	* Helper @ostream to endl.
	*/
	class endl_type {
	};

	/*
	* @endl_type @endl
	* Use for ostream::operator<<(endl_type) to endl.
	*/
	constexpr endl_type endl{};


	/*
	* class @ostream
	* Use __builtin_printf to output, won't use f**k stand @std::ostream
	*/
	class ostream {
	public:
		using char_type = char;
		//No more..

		ostream() const{
		}
		ostream(const ostream&) = delete;
		ostream(ostream&&) = default;

		//Output operator function(No @std::string or wchar_t or char16_t or char32_t)
		ostream operator<<(unsigned short);
		ostream operator<<(short);
		ostream operator<<(signed short);
		ostream operator<<(unsigned int);
		ostream operator<<(int);
		ostream operator<<(signed int);
		ostream operator<<(unsigned long);
		ostream operator<<(long);
		ostream operator<<(signed long);
		ostream operator<<(unsigned long long);
		ostream operator<<(long long);
		ostream operator<<(signed long long);
		ostream operator<<(unsigned float);
		ostream operator<<(float);
		ostream operator<<(signed float);
		ostream operator<<(unsigned double);
		ostream operator<<(double);
		ostream operator<<(signed double);
		ostream operator<<(char);
		ostream operator<<(const char*);
		ostream operator<<(endl_type);
	};

	//Extern @ostream @cout. Know that all know.
	extern ostream cout;
}

#include"estd_ostream.cpp"
#endif