#include <stdio.h>
#include <wiringPi.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "PCD8544.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<errno.h>   //errno
#include<sys/socket.h>  //socket
#include<netinet/in.h> //sockaddr_in
#include<arpa/inet.h>   //getsockname
#include<unistd.h>  //close
#include <ifaddrs.h>
#define TEMP_FILE_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_SIZE 32

// pin setup
int _din = 1;
int _sclk = 0;
int _dc = 2;
int _rst = 4;
int _cs = 3;

// lcd contrast
//may be need modify to fit your screen!  normal: 30- 90 ,default is:45 !!!maybe modify this value!
int contrast = 60;

int main (void)
{

  // print infos
  printf("Raspberry Pi PCD8544 sysinfo display\n");
  printf("========================================\n");

  // check wiringPi setup
  if (wiringPiSetup() == -1)
  {
  printf("wiringPi-Error\n");
    exit(1);
  }

  // init and clear lcd
  LCDInit(_sclk, _din, _dc, _cs, _rst, contrast);
  LCDclear();

  // show logo
  LCDshowLogo();

  delay(2000);

  for (;;)
  {
    // clear lcd
    LCDclear();
	struct ifaddrs *ifap, *ifa;
	struct sockaddr_in *sa;
	char *addr;
	getifaddrs(&ifap);

	for(ifa = ifap; ifa; ifa = ifa->ifa_next)
	{
		if(ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET)
		{
			sa = (struct sockaddr_in *) ifa->ifa_addr;
			addr = inet_ntoa(sa->sin_addr);
			printf("Interface = %s , addr= %s \n",ifa->ifa_name,addr);
            LCDdrawstring(0, 0, ifa->ifa_name);
            LCDdrawstring(0, 12, addr);
                // get system usage / info
            struct sysinfo sys_info;
            if(sysinfo(&sys_info) != 0)
            {
              printf("sysinfo-Error\n");
            }

            // uptime
            char uptimeInfo[15];
            unsigned long uptime = sys_info.uptime / 60;
            sprintf(uptimeInfo, "Uptime %ld min.", uptime);

            // cpu info
            char cpuInfo[10];
            unsigned long avgCpuLoad = sys_info.loads[0] / 1000;
            sprintf(cpuInfo, "CPU  %ld%%", avgCpuLoad);

            // ram info
            char ramInfo[10];
            unsigned long totalRam = sys_info.freeram / 1024 / 1024;
            sprintf(ramInfo, "RAM  %ld MB", totalRam);

            // cpu Temperature
            char cputemperature[15];
            float cpu_temperature_Result = Get_Cpu_Temperature();
            sprintf(cputemperature, "TEMP %.2f C", cpu_temperature_Result);


        //    LCDdrawstring(0, 0, addr);
            LCDdrawline(0, 10, 83, 10, BLACK);
            //LCDdrawstring(0, 12, uptimeInfo);
            LCDdrawstring(0, 20, cpuInfo);
            LCDdrawstring(0, 28, ramInfo);
            LCDdrawstring(0, 36, cputemperature);
            LCDdisplay();

            delay(3000);
		}
	}
	freeifaddrs(ifap);



  }



  return 0;
}

int Get_Cpu_Temperature(void)
{
    int fd;
    double temp = 0;
    char buf[MAX_SIZE];

    // open/sys/class/thermal/thermal_zone0/temp
    fd = open(TEMP_FILE_PATH, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "failed to open thermal_zone0/temp\n");
        return -1;
    }

    // read temperature
    if (read(fd, buf, MAX_SIZE) < 0) {
        fprintf(stderr, "failed to read temp\n");
        return -1;
    }

    // print as float
    temp = atoi(buf) / 1000.0;

    // close file
    close(fd);
    return temp;
}
