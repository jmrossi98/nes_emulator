#include "olc6502.h"
#include "Bus.h"

olc6502::olc6502(){}

olc6502::~olc6502(){}

uint8_t olc6502::read(uint16_t a)
{
    return bus->read(a, false);
}

void olc6502::write(uint16_t a, uint8_t d)
{
    return bus->write(a, d);
}