#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "wave.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace boost::asio;

int main(int argc, char **argv)
{
    bool devfile = false;
    if(argc==2)
	{
        printf("read : %s\n",argv[1]);
	}else if(argc==3){
        devfile = true;
        printf("read : %s\n",argv[1]);
        printf("device : %s\n",argv[2]);
    }
    else{
		printf("argument required (mp3 file)!\n");
		exit(1);
    }


    MONO_PCM pcmForWrite, pcmForRead;
    int i;
   
    monoWaveRead(&pcmForRead, argv[1]);
    printf("size = %ld\n",pcmForRead.s.size());
    std::string tst;

    int counter = 0;

    try {
		io_service io;
		serial_port port( io, devfile ? argv[2] :"/dev/ttyUSB0" );
		port.set_option(serial_port_base::baud_rate(115200));
		port.set_option(serial_port_base::character_size(8));
		port.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));
		port.set_option(serial_port_base::parity(serial_port_base::parity::none));
		port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
        	write(port,buffer(pcmForRead.s));
 
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

    return 0;
}
