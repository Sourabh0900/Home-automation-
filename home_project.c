#include <LPC21xx.H>
#include "header20.h"
#define LED1 1<<17
#define LED2 1<<18

main()
{
	u8 cmd;
	uart0_init(9600);
	IODIR0=LED1|LED2;
	IOSET0=LED1|LED2;
	while(1)
	{
		uart0_tx_string("Menu\r\n");
		uart0_tx_string("a.LED1 ON\r\n");
		uart0_tx_string("b.LED1 OFF\r\n");
		uart0_tx_string("c.LED2 ON\r\n");
		uart0_tx_string("d.LED2 OFF\r\n");
		uart0_tx_string("e.LED1&LED2 ON\r\n");
		uart0_tx_string("f.LED1&LED2 OFF\r\n");

		cmd=uart0_rx();
		uart0_tx(cmd);

		switch(cmd)
		{
			case 'a' :IOCLR0=LED1; break;
			case 'b' :IOSET0=LED1; break;
			case 'c' :IOCLR0=LED2; break;
			case 'd' :IOSET0=LED2; break;
			case 'e' :IOCLR0=LED1|LED2; break;
			case 'f' :IOSET0=LED1|LED2; break;
			default:
					uart0_tx_string("Wrong input\n\r");
		}
		 				uart0_tx_string("\n\r");
		}
	}