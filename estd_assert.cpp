#ifndef _ESTD_ASSERT_CPP_
#define _ESTD_ASSERT_CPP_
#include"estd_assert.h"

namespace estd {
	void dynamic(bool __assert,
		const char* __message,
		short __assert_level,
		error_level __level,
		const char* __file,
		const char* __function,
		int __line) {

		if (__assert||__assert_level>assert_level)
			return;

		std::ostringstream oss;
		oss << "Debug assertion failed!\n\n";
		if(__file != "")
			oss << "File:"
				<< __file;
		if(__function != "")
			oss << "\nFunction:"
			    << __function;

		if (!__line) { 
			oss << "\nLine:"
				<< __line;
		}

		oss <<"\n\nExpression:"
			<< __message
			<<" \n";

		std::cerr << oss.str();
	}
}

#endif