#pragma once
#include<fstrem>
#include<sstream>
#include<string>

namespace estd {
	/*
	* class @storable.
	* Storable infinte, don't destory with prog exit.
	* Store as stringstream.
	*/
	
	class storable {
	public:
		using char_type = char;
		using storable_elem = std::string;
	};
}