SECTIONS {
	__sr_driver_list : {
		drivers_list = .;
		KEEP(*("__sr_driver_list"));
		QUAD(0);
		PROVIDE(drivers_end = .);
	}
}
