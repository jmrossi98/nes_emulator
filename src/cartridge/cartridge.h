#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "../mapper/Mapper_000.h"

class Cartridge
{
public:	
	Cartridge(const std::string& sFileName);
	~Cartridge();

public:
	bool ImageValid();

	enum MIRROR
	{
		HORIZONTAL,
		VERTICAL,
		ONESCREEN_LO,
		ONESCREEN_HI,
	} mirror = HORIZONTAL;

private:
    bool bImageValid = false;

	std::vector<uint8_t> vPRGMemory;
	std::vector<uint8_t> vCHRMemory;
    
    uint8_t nMapperID = 0;
    uint8_t nPRGBanks = 0;
    uint8_t nCHRBanks = 0;

    std::shared_ptr<Mapper> pMapper;

public:
    // Main bus comms
	bool cpuRead(uint16_t addr, uint8_t &data);
	bool cpuWrite(uint16_t addr, uint8_t data);

	// PPU bus comms
	bool ppuRead(uint16_t addr, uint8_t &data);
	bool ppuWrite(uint16_t addr, uint8_t data);
};