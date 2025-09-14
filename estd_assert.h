#pragma once
#include<string>
#include<sstream>
#include<map>
#include<vector>

namespace estd {

	/*
	* short __estd_default_assert_level
	* Default assert level.
	* The value is 5.
	*/
	constexpr short __estd_default_assert_level = 5;  

	/*
	* int assert_level
	* User can set this assert level, so it's mutable.
	* It has 5 level:
	* 1     Weak check
	* 2     Release check
	* 3     Normal check
	* 4     Debug check
	* 5     Strong check.
	*/
	short assert_level = __estd_default_assert_level;

	/*
	* enum error_level
	* Level of error.
	* 4 levels:
	* error
	* warning
	* information
	* log
	*/
	enum error_level : int {
		error,
		warning,
		information,
		log
	};

	/*
	* std::map error_levevl_message
	* Get error level's string.
	*/
	const std::map<error_level, std::string> error_level_message = {
		{error_level::error,"Error"},
		{error_level::warning,"Warning"},
		{error_level::information,"Infomation"},
		{error_level::log,"Log"}
	};
	
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
		int __line = -1);
}

#include"estd_assert.cpp"