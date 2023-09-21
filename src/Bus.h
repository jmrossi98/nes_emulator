#pragma once

#include <cstdint>
#include <array>
#include <memory>

#include "./cpu/olc6502.h"
#include "./ppu/olc2C02.h"
#include "./cartridge/cartridge.h"

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

    // GamePak Cartridge
    std::shared_ptr<Cartridge> cart;

    // 2KB RAM
    std::array<uint8_t, 2048> cpuRam;

public:
    void cpuWrite(uint16_t addr, uint8_t data);
    uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);
};