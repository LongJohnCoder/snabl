#include "snabl/box.hpp"
#include "snabl/type.hpp"

namespace snabl {
	Box::Box(const ATypePtr &type): _type(type), _value(nullptr), _is_undef(true) { }

	const ATypePtr &Box::type() const { return _type; }

	bool Box::is_undef() const { return _is_undef; }

	bool Box::is_equid(const Box &rhs) const {
		if (rhs.type() != _type) { return false; }
		return _type->is_equid(*this, rhs);
	}

	bool Box::is_eqval(const Box &rhs) const {
		if (rhs.type() != _type) { return false; }
		return _type->is_eqval(*this, rhs);
	}

	Cmp Box::cmp(const Box &rhs) const {
		auto rt(rhs.type());
		if (rt != _type) { return snabl::cmp(_type->tag, rt->tag); }
		return _type->cmp(*this, rhs);
	}

	void Box::dump(std::ostream &out) const { _type->dump(*this, out); }

	void Box::write(std::ostream &out) const { _type->write(*this, out); }
}
