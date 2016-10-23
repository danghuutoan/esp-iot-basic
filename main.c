#include <stdio.h>
#include "osapi.h"
#include "user_interface.h"
#include "ets_sys.h"
#include "osapi.h"
#include "ip_addr.h"
#include "espconn.h"
#include "mem.h"

LOCAL void ICACHE_FLASH_ATTR
udp_callback(void *arg, char *pdata, unsigned short len)
{
    os_printf("%s:Received udp data: %s \r\n",__FUNCTION__, pdata);
}

void init_udp(void)
{
    esp_udp ssdp_udp;
    struct espconn pssdpudpconn;
	ssdp_udp.local_port = 8080;
	pssdpudpconn.type = ESPCONN_UDP;
	pssdpudpconn.proto.udp = &(ssdp_udp);
	espconn_regist_recvcb(&pssdpudpconn, udp_callback);
	espconn_create(&pssdpudpconn);             
}

void app_init()
{
    uart_div_modify(0, UART_CLK_FREQ / 115200);
    os_delay_us(1000000);
    os_printf("\r\nudp test udp esp8266 %s\r\n", __TIME__);
    init_udp();
}

void user_init(void)
{
    system_init_done_cb(app_init);
}

