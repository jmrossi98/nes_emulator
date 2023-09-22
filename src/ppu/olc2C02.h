#pragma once

#include <cstdint>
#include <memory>

#include "../cartridge/Cartridge.h"

#include "../../olcPixelGameEngine.h"

class olc2C02
{
public:
    olc2C02();
    ~olc2C02();

private:
    // GamePak Cartridge
    std::shared_ptr<Cartridge> cart;

    uint8_t tblName[2][1024];
    uint8_t tblPalette [32];

private:
	olc::Pixel  palScreen[0x40];
	// In Video
	// olc::Sprite sprScreen = olc::Sprite(256, 240);
	// olc::Sprite sprNameTable[2] = { olc::Sprite(256, 240), olc::Sprite(256, 240) };
	// olc::Sprite sprPatternTable[2] = { olc::Sprite(128, 128), olc::Sprite(128, 128) };

	// Changed To for API breaking subsequent PGE Update
	olc::Sprite* sprScreen;
	olc::Sprite* sprNameTable[2];
	olc::Sprite* sprPatternTable[2];

public:
	// Debugging Utilities
	olc::Sprite& GetScreen();
	olc::Sprite& GetNameTable(uint8_t i);
	olc::Sprite& GetPatternTable(uint8_t i);
	bool frame_complete = false;

public:
    // Main bus comms
    uint8_t cpuRead(uint16_t addr, bool rdonly = false);
    void cpuWrite(uint16_t addr, uint8_t data);

    // PPU bus comms
    uint8_t ppuRead(uint16_t addr, bool rdonly = false);
    void ppuWrite(uint16_t addr, uint8_t data);

    void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
    void clock();
};
