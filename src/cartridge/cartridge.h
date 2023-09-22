#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Cartridge
{
public:	
	Cartridge();
	~Cartridge();

private:
    std::vector<uint8_t> vPRFMemory;
    std::vector<uint8_t> vCHRMemory;
    
    uint8_t nMapperID = 0;
    uint8_t nPRGBanks = 0;
    uint8_t nCHRBanks = 0;

    std::shared_ptr<Mapper> pMapper;

public:
    // Main bus comms
    uint8_t cpuRead(uint16_t addr, bool rdonly = false);
    void cpuWrite(uint16_t addr, uint8_t data);

    // PPU bus comms
    uint8_t ppuRead(uint16_t addr, bool rdonly = false);
    void ppuWrite(uint16_t addr, uint8_t data);
};