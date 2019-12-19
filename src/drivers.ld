SECTIONS {
	.rodata.drivers_list : {
		drivers_list = .;
		KEEP(*(".rodata.drivers"));
		QUAD(0);
		PROVIDE(drivers_end = .);
	}
}
