#pragma once

#include "Mapper.h"

class Mapper_003 : public Mapper
{
public:
	Mapper_003(uint8_t prgBanks, uint8_t chrBanks);
	~Mapper_003();

	bool cpuMapRead(uint16_t addr, uint32_t &mapped_addr, uint8_t &data);
	bool cpuMapWrite(uint16_t addr, uint32_t &mapped_addr, uint8_t data = 0);
	bool ppuMapRead(uint16_t addr, uint32_t &mapped_addr);
	bool ppuMapWrite(uint16_t addr, uint32_t &mapped_addr);
	void reset();

private:
	uint8_t nCHRBankSelect = 0x00;


};
