#ifndef SNABL_BIN_HPP
#define SNABL_BIN_HPP

#include <deque>
#include <map>

#include "snabl/fimp.hpp"
#include "snabl/op.hpp"
#include "snabl/std/optional.hpp"

namespace snabl {
	using Pos = size_t;
	
	class Bin {
	public:
		Bin();
		std::optional<Pos> get_fimp_pos(const AFimpPtr &ptr);
	private:
		std::map<AFimpPtr, Pos> _fimps;
		std::deque<Op> _ops;
	};
}

#endif