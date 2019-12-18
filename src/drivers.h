void iterate_drivers(void);

#define DRIVER_DECORATION __attribute__((used, section("driver_items")))
#define DECLARE_DRIVER(name, id) \
	static const int driver_ ## name ## _detail DRIVER_DECORATION = id;
