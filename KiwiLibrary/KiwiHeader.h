#pragma once
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <cmath>

#include <array>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <deque>
#include <bitset>

#include <algorithm>
#include <functional>
#include <numeric>

#include <string>
#include <sstream>
#include <iostream>

#include <memory>
#include <locale>
#include <codecvt>

#include <chrono>
#include <mutex>
#include <thread>

using namespace std;

#define TRIE_ALLOC_ARRAY
#define DIVIDE_BOUND 6
#define MIN_CANDIDATE 5
#define USE_DIST_MAP
#define PMI_WEIGHT 1.7f
//#define LOAD_TXT
#define CUSTOM_ALLOC

#ifdef _WIN32
typedef wchar_t k_wchar;
typedef wstring k_wstring;
#define KSTR(x) L##x
#else
typedef char16_t k_wchar;
typedef u16string k_wstring;
#define KSTR(x) u##x
inline int fopen_s(FILE** f, const char* p, const char* m)
{
	*f = fopen(p, m);
	return !*f;
}
#endif

#include "KMemory.h"

#ifdef CUSTOM_ALLOC
typedef basic_string<char, char_traits<char>, spool_allocator<char>> k_string;
#ifdef _WIN32
#else
namespace std
{
	template <>
	class hash<k_string> {
	public:
		size_t operator() (const k_string& o) const
		{
			return hash<string>{}(string{ o.begin(), o.end() });
		};
	};
}
#endif
typedef basic_stringstream<char, char_traits<char>, spool_allocator<char>> k_stringstream;
typedef vector<char, pool_allocator<char>> k_vchar;
typedef vector<pair<k_vchar, float>, pool_allocator<pair<k_vchar, float>>> k_vpcf;
#include "KMemoryChar.h"
#else
typedef string k_string;
typedef stringstream k_stringstream;
typedef vector<char> k_vchar;
typedef vector<pair<k_vchar, float>> k_vpcf;
#endif