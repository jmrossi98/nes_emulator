#include "Bus.h"

Bus::Bus()
{
    // Connect CPU to bus
    cpu.ConnectBus(this);
}

Bus::~Bus(){}

void Bus::cpuWrite(uint16_t addr, uint8_t data)
{
    if (addr >= 0x0000 && addr <= 0xFFFF)
        cpuRam[addr] = data;
}

uint8_t Bus::cpuRead(uint16_t addr, bool bReadOnly)
{
    uint8_t data = 0x00;

    if (addr >= 0x0000 && addr <= 0x1FFF)
    {
        data = cpuRam[addr & 0x07FF];
    }

    return data;
}
