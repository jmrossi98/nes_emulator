#include "olc2C02.h"

olc2C02::olc2C02()
{
}

olc2C02::~olc2C02()
{
	delete sprScreen;
	delete sprNameTable[0];
	delete sprNameTable[1];
	delete sprPatternTable[0];
	delete sprPatternTable[1];
}

olc::Sprite& olc2C02::GetScreen()
{
	return *sprScreen;
}

olc::Sprite & olc2C02::GetNameTable(uint8_t i)
{
	return *sprNameTable[i];
}

olc::Sprite & olc2C02::GetPatternTable(uint8_t i)
{
	return *sprPatternTable[i];
}

uint8_t olc2C02::cpuRead(uint16_t addr, bool rdonly)
{
	uint8_t data = 0x00;

	switch (addr)
	{
	case 0x0000: // Control
		break;
	case 0x0001: // Mask
		break;
	case 0x0002: // Status
		break;
	case 0x0003: // OAM Address
		break;
	case 0x0004: // OAM Data
		break;
	case 0x0005: // Scroll
		break;
	case 0x0006: // PPU Address
		break;
	case 0x0007: // PPU Data
		break;
	}

	return data;
}

void olc2C02::cpuWrite(uint16_t addr, uint8_t data)
{
	switch (addr)
	{
	case 0x0000: // Control
		break;
	case 0x0001: // Mask
		break;
	case 0x0002: // Status
		break;
	case 0x0003: // OAM Address
		break;
	case 0x0004: // OAM Data
		break;
	case 0x0005: // Scroll
		break;
	case 0x0006: // PPU Address
		break;
	case 0x0007: // PPU Data
		break;
	}
}

uint8_t olc2C02::ppuRead(uint16_t addr, bool rdonly)
{
	uint8_t data = 0x00;
	addr &= 0x3FFF;

	if (cart->ppuRead(addr, data))
	{

	}

	return data;
}

void olc2C02::ppuWrite(uint16_t addr, uint8_t data)
{
	addr &= 0x3FFF;

	if (cart->ppuWrite(addr, data))
	{

	}
}

void olc2C02::ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge)
{
	this->cart = cartridge;
}

void olc2C02::clock()
{
}
