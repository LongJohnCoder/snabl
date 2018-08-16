#include <cassert>

#include "snabl/call.hpp"
#include "snabl/env.hpp"
#include "snabl/func.hpp"
#include "snabl/type.hpp"

using namespace snabl;

static void add_int(Call &call) {
}

int main() {
	Env env;
	auto add(env.lobby.add_func<2, 1>(env.get_sym("+")));
	
	Func<2, 1>::add_fimp(add,
											 {env.int_type, env.int_type},
											 {env.int_type},
											 add_int);
	
	//env.bin.compile(add_int);
	
	auto s(env.begin(env.scope()));
	env.push_stack(env.int_type, Int(42));
	assert(s->pop_stack().as<Int>() == Int(42));
	auto foo(env.get_sym("foo"));
	env.main->set_var(foo, env.int_type, Int(42));
	assert(s->get_var(foo)->as<Int>() == Int(42));
	env.end();

	env.bin.emit_push(Box(env.int_type, Int(42)));
	return 0;
}
