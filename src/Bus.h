#pragma once

#include <cstdint>
#include <memory>

#include "./cpu/olc6502.h"
#include "./ppu/olc2C02.h"
#include "./cartridge/Cartridge.h"

class Bus
{
public:
    Bus();
    ~Bus();

public: // Devices on bus

    // OLC6502 Central Processing Unit
    olc6502 cpu;

    // OLC2C02 Picture Processing Unit
    olc2C02 ppu;

    // 2KB RAM
    uint8_t cpuRam[2048];

    // GamePak Cartridge
    std::shared_ptr<Cartridge> cart;

	// Controllers
	uint8_t controller[2];

public:
    void cpuWrite(uint16_t addr, uint8_t data);
    uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

	// Connects a cartridge object, takes one system tick
	void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void reset();
	void clock();

private:
	uint32_t nSystemClockCounter = 0;
    uint8_t controller_state[2];
};
