#ifndef RUNTIME_REGISTER_H
#define RUNTIME_REGISTER_H

struct driver_details;
void runtime_register_driver(const struct driver_details *details);

typedef void (*driver_iter_cb)(const struct driver_details *details, void *cb_data);
void runtime_iterate_drivers(driver_iter_cb cb_func, void *cb_data);

#define REGISTER_DRIVER(name, id, func) \
	/* TODO */

#endif /* RUNTIME_REGISTER_H */
