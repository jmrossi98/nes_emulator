#pragma once

class Cartridge
{
public:	
	Cartridge();
	~Cartridge();

    // Main bus comms
    uint8_t cpuRead(uint16_t addr, bool rdonly = false);
    void cpuWrite(uint16_t addr, uint8_t data);

    // PPU bus comms
    uint8_t ppuRead(uint16_t addr, bool rdonly = false);
    void ppuWrite(uint16_t addr, uint8_t data);
};