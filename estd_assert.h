#pragma once
#include<string>
#include<sstream>
#include<map>
#include<exception>

namespace estd {

	/*
	* enum assert_handle
	* Handle when assert failed.
	* It has 5 member:
	* _abort       Call std::terminate().
	* _throw       Throw assert_error.
	* _print       Print error.
	* _print_abort Print error, and abort.
	* _print_throw Print error, and throw error.
	*/
	enum assert_handle : char {
		_abort,
		_throw,
		_print,
		_print_abort,
		_print_throw
	};

	/*
	* assert_handle default_assert_handle
	* Default handle when assert failed.
	* The value is assert_handle::_print.
	*/
	constexpr assert_handle default_assert_handle = assert_handle::_print;
	
	/*
	* short __estd_default_assert_level
	* Default assert level.
	* The value is 5.
	*/
	constexpr unsigned short __estd_default_assert_level = 5;  

	/*
	* extern int assert_level
	* User can set this assert level, so it's mutable.
	* It has 5 level:
	* 1     Weak check.
	* 2     Release check.
	* 3     Normal check.
	* 4     Debug check.
	* 5     Strong check.
	* 
	* It will define in .cpp file.
	*/
	extern short assert_level;

	/*
	* enum error_level
	* Level of error.
	* 4 levels:
	* error.
	* warning.
	* information.
	* log.
	*/
	enum error_level : char {
		error,
		warning,
		information,
		log
	};

	/*
	* extern std::map error_levevl_message
	* Get error level's string.
	* It will define in .cpp file.
	*/
	extern const std::map<error_level, std::string> error_level_message;
	
	/*
	* class assert_error
	* exception based from assert_error
	* For dynamic assert.
	*/
	class assert_error : public std::exception {
	public:
		using base = std::exception;
		using error_type = const char*;

		explicit assert_error(error_type _e) :message{ _e }
		{
		}

		assert_error(const char* _m,
			error_level _l,
			const char* _file = "",
			const char* _func = "",
			int _line = -1) : message{ _m },
			level{ _l },
			file{ _file },
			function{ _func },
			line{ _line } {

		}
		
		inline const char* what() const override {
			return message;
		}

		//Assert information.
		const char* message;
		error_level level{ error_level::error };
		const char* file{};
		const char* function{};
		int line{ -1 };  //Default line.
	};

	/*
	* function __exception_maker
	* Helper function for dynamic() and user.
	*/
	inline assert_error __exception_maker(
		const char* __message,
		error_level __level,
		const char* __file = "",
		const char* __function = "",
		int __line = -1) {
		return assert_error{
			__message,__level,__file,__function,__line
		};
	}
	/*
	* template<Om> function __print_error
	* Helper function for dynamic().
	*/
	template<typename _Om = std::ostream>
	_Om& __print_error(_Om& __out_stream,
		const char* __message,
		error_level __level,
		const char* __file = "",
		const char* __function = "",
		int __line = -1) {
		std::ostringstream oss;
		oss << "Debug assertion failed!\n\n";
		if (__file != "")
			oss << "File:"
			<< __file;
		if (__function != "")
			oss << "\nFunction:"
			<< __function;

		if (__line != -1) {
			oss << "\nLine:"
				<< __line;
		}

		oss << "\n\nExpression:"
			<< __message
			<< " \n";

		return __out_stream << oss.str();
	}

	/*
	* Another template<_Om> function __print_error
	* Print out assert_error.
	*/
	template<typename _Om = std::ostream>
	inline _Om& __print_error(_Om& __out_stream,
		assert_error __error
	) {
		return __print_error<_Om>(
			__out_stream,
			__error.message,
			__error.level,
			__error.file,
			__error.function,
			__error.line
		);
	}

	/*
	* function dynamic
	* bool           __assert			Assert.
	  const char*    __message			Error meassage.
	  short          __assert_level	
	  Assert stronge level.
	  1 is more necessary, 5 is more unnecessary.
	  error_level   __level			Check's level.
	  const char*    __file			Name of assert file.
	  const char*    __line			Number of assert line.
	  
	* For example:
	* estd::dynamic(1>2, 
		"114514", 
		1,
		estd::error, 
		__FILE__, 
		__FUNCSIG__);

	* It may print out:
	* Debug assertion failed!

	  File:E:\s\my\IDE\C++\my_lib\estd\test\main.cpp
	  Function:int __cdecl main(int,char **,char **)

	  Expression:114514
	*/
	void dynamic(bool __assert,
		const char* __message,
		short __assert_level,
		error_level __level,
		const char* __file = "",
		const char* __function = "",
		int __line = -1,
		assert_handle __handle = default_assert_handle);
	/* 
	* Another function dynamic
	* Args:
	* bool             __assert			No need say more..
	* short            __assert_level	No need say more..
	* assert_error     __error			Include error infomations.
	*/
	void dynamic(bool __assert,
		short __assert_level,
		assert_error __error,
		assert_handle __handle = default_assert_handle);
}

#include"estd_assert.cpp"