/*
 * This is the public API. To iterate driver list items and access their
 * respective properties.
 */

void iterate_drivers(void);
void execute_drivers(void);

struct driver_details {
	int identification;
	const char *label;
	void (*callback)(void);
};

/*
 * These are internal details. Though individual drivers need to use
 * the DECLARE_DRIVER() declaration helper, they shall not care about
 * internal details of this implementation. Consider it opaque.
 */

struct driver_list_node {
	const struct driver_details *driver;
	struct driver_list_node *next;
};
void register_driver(struct driver_list_node *node);

#define ATTR_CONS __attribute__((constructor))

#define DECLARE_DRIVER(name, id, func) \
	static const struct driver_details driver_ ## name ## _detail = { \
		.identification = (id), \
		.label = #name, \
		.callback = (func), \
	}; \
	static struct driver_list_node driver_ ## name ## _node = { \
		.driver = &driver_ ## name ## _detail, \
	}; \
	static void driver_ ## name ## _register(void) ATTR_CONS; \
	static void driver_ ## name ## _register(void) { \
		register_driver(&driver_ ## name ## _node); \
	} \
	/* end of DECLARE_DRIVER() */
