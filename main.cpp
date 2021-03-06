/***********************************************************************
FILE MAIN.CPP CONTAINS DIFFERENT EXAMPLES OF LIBGPIOD LIBRARY USAGE.

TO INSTALL LIBGPIOD:
sudo apt-get install libgpiod-dev

FILE WRITEN BY ARTUR KALNINS (21.01.2021).
***********************************************************************/

#include <gpiod.h>

#include <iostream>
#include <string>

bool detect_gpio_chips();
void list_chip_lines( gpiod_chip* chip );

int main( int argc, char* argv[] )
{
	std::cout << "Test C++ Raspbery PI 4 GPIO: MAIN" << std::endl;

	detect_gpio_chips();

	return 0;
}

bool detect_gpio_chips()
{
	auto it = gpiod_chip_iter_new();

	if( !it )
	{
		std::cout << "Unable to access GPIO chips." << std::endl;
		return false;
	}

	gpiod_chip* chip {nullptr};
	gpiod_foreach_chip( it, chip )
	{
		std::cout << "============ GPIO CHIP ============\n";
		std::cout << "Chip name:\t\t" << gpiod_chip_name( chip ) << std::endl;
		std::cout << "Chip label:\t\t" << gpiod_chip_label( chip ) << std::endl;
		std::cout << "Chip num. lines:\t" << gpiod_chip_num_lines( chip ) << std::endl;

		list_chip_lines( chip );
	}

	gpiod_chip_iter_free( it );

	// or call  //gpiod_chip_close( chip ); to free the chip

	return true;
}

void list_chip_lines( gpiod_chip* chip )
{
	auto it = gpiod_line_iter_new( chip );
	if( !it )
	{
		std::cout << "Error creating line iterator.\n";
		return;
	}

	gpiod_line* line {nullptr};
	gpiod_foreach_line( it, line )
	{
		int direction = gpiod_line_direction( line );
		int active_state = gpiod_line_active_state( line );
		uint32_t offset = gpiod_line_offset( line );

		//string name{ gpiod_line_name( line ) };
		//string consumer{ gpiod_line_consumer( line ) };

		std::cout << "Offset: " << offset
				  << " dir: " << ( direction == GPIOD_LINE_DIRECTION_INPUT ? "input" : "output" )
				  << "\tstate: " << ( active_state == GPIOD_LINE_ACTIVE_STATE_LOW ? "low" : "high" )
				  << " name: " << ( gpiod_line_name( line ) == nullptr ? "unnamed" : gpiod_line_name( line ) )
				  << "\tconsumer: "
				  << ( gpiod_line_consumer( line ) == nullptr ? "unused" : gpiod_line_consumer( line ) ) << std::endl;
	}

	gpiod_line_iter_free( it );
}
