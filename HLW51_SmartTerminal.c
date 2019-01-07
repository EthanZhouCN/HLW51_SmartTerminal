#include ""
#define REPORT_INTERVAL			1
#define HEARTBEAT_INTERVAL		120
#define YES						1
#define NO						0
#define CMD_MAC_LEN				10
typedef struct{
	unsigned char report_timeout_flag;
	unsigned char heartbeat_timeout_flag;
	unsigned char link_status;
	unsigned char login_status;
	unsigned char recv_cmd[CMD_MAC_LEN];
}g_t;

g_t g;
unsigned char sec = 0;

void init_hw()
{

}
void init_timer()
{

}

int main()
{
	init_hw();
	init_timer();

	while(1)
	{
		if(g.link_status == NO)
		{
			//connect
			g.link_status = YES;
		}
		else if(g.login_status == NO)
		{
			//login
			g.login_status = YES;
			
		}
		else if(g.heartbeat_timeout_flag == YES)
		{
			//send heartbeat
		} 
		else if(g.report_timeout_flag == YES)
		{
			//send report
		}
		else if(g.recv_cmd[0] != 0)
		{
			//handle cmd from platfrom

			g.recv_cmd[0] = 0x00;
		}

	}
	
}

void uart_recv_cb()
{
	
}

void timer1s_cb()
{
	sec++;
	
	if(g.login_status == YES)
	{

		if(sec % REPORT_INTERVAL == 0)
		{
			g.report_timeout_flag = YES;
		}

		if(sec % HEARTBEAT_INTERVAL == 0)
		{
			g.heartbeat_timeout_flag = YES;
		}

	}
}



