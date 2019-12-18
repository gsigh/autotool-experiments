SECTIONS {
	.rodata.driver_list : {
		QUAD(0);
		/* PROVIDE(drivers_list = .); */
		drivers_list = .;
		KEEP(*(*driver_items));
		QUAD(0);
		PROVIDE(drivers_end = .);
	}
}
INSERT AFTER .text;
