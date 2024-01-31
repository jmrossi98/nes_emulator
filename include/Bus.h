#pragma once

#include <cstdint>
#include <memory>

#include "olc6502.h"
#include "olc2C02.h"
#include "Cartridge.h"

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
    // Read/write on CPU
    void cpuWrite(uint16_t addr, uint8_t data);
    uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

	// Connects a cartridge object, takes one system tick
	void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void reset();
	void clock();

private:
    // Keep track of clock cycles
	uint32_t nSystemClockCounter = 0;

    // Track controller state
    uint8_t controller_state[2];

    // Direct Memory Access varialbes
	uint8_t dma_page = 0x00;
	uint8_t dma_addr = 0x00;
	uint8_t dma_data = 0x00;
	bool dma_dummy = true;
	bool dma_transfer = false;
};
