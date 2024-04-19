#ifndef __OPTION_H
#define __OPTION_H

#include <stdbool.h>

typedef enum {
	SOME,
	NONE,
} option_tag;

typedef struct {
	option_tag t;
	void *data;
} option;

typedef void* (*transform) (void *);

option some(void *data);
option none(void);

option is_some_and(option o, transform fun);
option is_none_and(option o, transform fun);

bool is_some(option o);
bool is_none(option o);

// TODO: Implement this
void *unwrap(option o);
void *unwrap_or(option o, void *default_value);

#ifdef OPTION_IMPL

option some(void *data) {
	return (option) {
		.t = SOME,
		.data = data,
	};
}

option none(void) {
	return (option) {
		.t = NONE,
		.data = NULL,
	};
}

bool is_some(option o) {
	return o.t == SOME;
}

bool is_none(option o) {
	return o.t == NONE;
}

option is_some_and(option o, transform fun) {
	if (is_some(o)) {
		o.data = fun(o.data);
		return o;
	} else {
		return o;
	}
}

option is_none_and(option o, transform fun) {
	if (is_none(o)) {
		o.data = fun(o.data);
		return o;
	} else {
		return o;
	}
}

void *unwrap(option o) {
	return o.data;
}

#endif // OPTION_IMPL
#endif // !__OPTION_H
