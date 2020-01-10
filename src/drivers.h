void iterate_drivers(void);
void execute_drivers(void);

struct driver_details {
	int identification;
	const char *label;
	void (*callback)(void);
};
extern const struct driver_details *drivers_list[];
extern const struct driver_details *drivers_end[];

#ifdef __APPLE__
#define SR_DRIVER_LIST_SECTION "__DATA,__sr_driver_list"
#else
#define SR_DRIVER_LIST_SECTION "__sr_driver_list"
#endif

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
		DRIVER_DECORATION = &driver_ ## name ## _detail
