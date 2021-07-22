/***********************************************************************
FILE MAIN.CPP CONTAINS DIFFERENT EXAMPLES OF LIBGPIOD LIBRARY USAGE.

FOR THIS EXAMPLE TI RUN YOU MUST INSTALL LIBGPIOD LBIRARY.

FILE WRITEN BY ARTUR KALNINS (21.01.2021).
***********************************************************************/
#include <gpiod.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void blink_led_thread_2( gpiod_line* led );
bool is_button_pressed( gpiod_line* button );

int main( int argc, char* argv[] )
{
	std::cout << "Test C++ Raspbery PI 4 GPIO : IO TEST" << std::endl;

	gpiod_chip* chip = gpiod_chip_open_by_name( "gpiochip0" );

	if( !chip )
	{
		cout << "ERROR: Couldn't open the chip: gpiochip0\n";
		exit( -1 );
	}

	auto* led = gpiod_chip_get_line( chip, 24 );
	auto* led2 = gpiod_chip_get_line( chip, 25 );
	auto* btn = gpiod_chip_get_line( chip, 17 );

	auto rslt = gpiod_line_request_output( led, "io_test", 0 );

	rslt = gpiod_line_request_output( led2, "io_test", 0 );

	if( rslt < 0 )
	{
		cout << "ERROR: Couldn't set up pin 24 as output.\n";
	}

	//rslt = gpiod_line_request_input_flags( btn, "io_test", GPIOD_CTXLESS_FLAG_BIAS_PULL_UP );
	rslt = gpiod_line_request_input( btn, "io_test" );

	if( rslt < 0 )
	{
		cout << "ERROR: Couldn't set up pin 23 as input.\n";
	}

	std::thread th( blink_led_thread_2, led2 );

	int msg_no {0};
	while( true )
	{
		auto rslt = is_button_pressed( btn );
		if( rslt )
		{
			//cout << msg_no << " BTN is pressed.\n";
			gpiod_line_set_value( led, 1 );
			msg_no++;
		}
		else
		{
			gpiod_line_set_value( led, 0 );
		}
	}

	th.join();

	gpiod_line_release( led );
	gpiod_line_release( btn );
	gpiod_chip_close( chip );

	return 0;
}

void led_blink()
{
	gpiod_chip* chip = gpiod_chip_open_by_name( "gpiochip0" );

	if( !chip )
	{
		cout << "ERROR: Couldn't open the chip: gpiochip0\n";
		exit( -1 );
	}

	gpiod_line* led = gpiod_chip_get_line( chip, 24 );

	auto rslt = gpiod_line_request_output( led, "io_test", 0 );

	if( rslt < 0 )
	{
		cout << "ERROR: Couldn't set up pin 24 as output.\n";
	}

	int no {0};

	while( true )
	{
		if( no == 0 )
		{
			no = 1;
			gpiod_line_set_value( led, 1 );
		}
		else
		{
			no = 0;
			gpiod_line_set_value( led, 0 );
		}

		this_thread::sleep_for( chrono::milliseconds( 500 ) );
	}
}

void blink_led_thread_2( gpiod_line* led )
{
	int no = 0;

	while( true )
	{
		if( no == 0 )
		{
			no = 1;
			gpiod_line_set_value( led, 1 );
		}
		else
		{
			no = 0;
			gpiod_line_set_value( led, 0 );
		}

		this_thread::sleep_for( chrono::milliseconds( 250 ) );
	}
}

bool is_button_pressed( gpiod_line* button )
{
	// We read the input several times
	// to get more stable input (that can be altered by spikes)
	if( gpiod_line_get_value( button ) && gpiod_line_get_value( button ) && gpiod_line_get_value( button ) &&
		gpiod_line_get_value( button ) )
	{
		return true;
	}

	return false;
}