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
		int __line,
		assert_handle __handle) {

		if (__assert || __assert_level > assert_level)
			return;

		if(__handle == _print||__handle == _print_abort||__handle == _print_throw)
			__print_error(std::cout, __message, __level, __file, __function, __line);
		if (__handle == _abort || __handle == _print_abort)
			std::terminate();
		if (__handle == _throw || __handle == _print_throw)
			throw __exception_maker(
				__message,
				__level,
				__file,
				__function,
				__line
			);
		
	}
	
	void dynamic(bool __assert,
		short __assert_level,
		assert_error __error,
		assert_handle __handle = default_assert_handle) {
		return dynamic(__assert,
			__error.message, 
			__assert_level, 
			__error.level, 
			__error.file, 
			__error.function, 
			__error.line,
			__handle);
	}

	short assert_level = __estd_default_assert_level;
	const std::map<error_level, std::string> error_level_message = {
		{error_level::error,"Error"},
		{error_level::warning,"Warning"},
		{error_level::information,"Information"},
		{error_level::log,"Log"}
	};
}

#endif