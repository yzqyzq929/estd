#ifndef _ESTD_OSTREAM_CPP_
#define _ESTD_OSTREAN_CPP_
#ifdef __has_builtin
namespace estd {
	ostream::operator<<(int) {
		__builtin_printf("%")
	}
}
#endif
#endif