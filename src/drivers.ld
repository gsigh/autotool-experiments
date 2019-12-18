SECTIONS {
	driver_list : {
		PROVIDE(drivers_list = .);
		*(*driver_items);
		QUAD(0);
		PROVIDE(drivers_end = .);
	}
}
INSERT AFTER .text;
