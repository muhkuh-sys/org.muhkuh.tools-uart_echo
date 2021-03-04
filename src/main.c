
#include <string.h>

#include "netx_io_areas.h"
#include "systime.h"
#include "uart_standalone.h"
#include "uart.h"


/*-------------------------------------------------------------------------*/


UART_STANDALONE_DEFINE_GLOBALS

/* The echo_main function never returns. */
void echo_main(void) __attribute__ ((noreturn));

void echo_main(void)
{
	unsigned int uiChar;


	systime_init();
	uart_standalone_initialize();

	while(1)
	{
		/* Receive a character. */
		uiChar = uart_get(0);

		/* Swap the case of the character. */
		if( uiChar>='a' && uiChar<='z' )
		{
			uiChar = uiChar - 'a' + 'A';
		}
		else if( uiChar>='A' && uiChar<='Z' )
		{
			uiChar = uiChar - 'A' + 'a';
		}

		/* Send the character back. */
		uart_put(0, (unsigned char)(uiChar & 0xffU));
	};
}
