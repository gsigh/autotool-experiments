void iterate_drivers(void);
void execute_drivers(void);

struct driver_details {
	int identification;
	const char *label;
	void (*callback)(void);
};

void register_driver(const struct driver_details *details);

#ifdef __APPLE__
#define SR_DRIVER_LIST_SECTION "__DATA,__sr_driver_list"
#else
#define SR_DRIVER_LIST_SECTION "__sr_driver_list"
#endif
#define ATTR_CONS __attribute__((constructor))

#define DRIVER_DECORATION __attribute__((used, \
	section(SR_DRIVER_LIST_SECTION), \
	aligned(sizeof(struct driver_details *))))
#define DECLARE_DRIVER(name, id, func) \
	static const struct driver_details driver_ ## name ## _detail = { \
		.identification = (id), \
		.label = #name, \
		.callback = (func), \
	}; \
	static const struct driver_details *driver_ ## name ## _item \
		DRIVER_DECORATION = &driver_ ## name ## _detail; \
	static void driver_ ## name ## _register(void) ATTR_CONS; \
	static void driver_ ## name ## _register(void) { \
		register_driver(&driver_ ## name ## _detail); \
	} \
	/* end of DECLARE_DRIVER() */
