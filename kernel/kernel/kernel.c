#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	terminal_setcolor(terminal_getcolor(15, 0));
	printf("  __  __ _        ____   _____  \n");
	printf(" |  \\/  (_)      / __ \\ / ____| \n");
	terminal_setcolor(terminal_getcolor(1, 0));
	printf(" | \\  / |_ _ __ | |  | | (___   \n");
	printf(" | |\\/| | | '_ \\| |  | |\\___ \\  \n");
	terminal_setcolor(terminal_getcolor(4, 0));
	printf(" | |  | | | | | | |__| |____) | \n");
	printf(" |_|  |_|_|_| |_|\\____/|_____/  \n");
	terminal_setcolor(terminal_getcolor(2, 0));
	printf("                                \n");
	printf("hello\n");
	printf("world\n");
}
