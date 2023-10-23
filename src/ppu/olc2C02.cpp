#pragma once

#include "olc2C02.h"

olc2C02::olc2C02()
{
}

olc2C02::~olc2C02()
{
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

olc::Sprite& olc2C02::GetPatternTable(uint8_t i, uint8_t palette)
{
	// Planes are stored as 8 bytes of LSB, followed by 8 bytes of MSB. Loop through all 16x16 tiles
	for (uint16_t nTileY = 0; nTileY < 16; nTileY++)
	{
		for (uint16_t nTileX = 0; nTileX < 16; nTileX++)
		{
			// Convert the 2D tile coordinate into a 1D offset into the pattern table memory.
			uint16_t nOffset = nTileY * 256 + nTileX * 16;

			// Now loop through 8 rows of 8 pixels
			for (uint16_t row = 0; row < 8; row++)
			{

				// Read from pattern tables
				uint8_t tile_lsb = ppuRead(i * 0x1000 + nOffset + row + 0x0000);
				uint8_t tile_msb = ppuRead(i * 0x1000 + nOffset + row + 0x0008);

				// Iterate through the 8-bit words, combining them to give us the final pixel index
				for (uint16_t col = 0; col < 8; col++)
				{
					uint8_t pixel = (tile_lsb & 0x01) + (tile_msb & 0x01);

					// Shift the row words 1 bit right for each column of the character.
					tile_lsb >>= 1; tile_msb >>= 1;

					// We can translate to a screen colour, and coordinates of the sprite
					sprPatternTable[i]->SetPixel
					(
						nTileX * 8 + (7 - col),
						nTileY * 8 + row, 
						GetColourFromPaletteRam(palette, pixel)
					);
				}
			}
		}
	}

	return *sprPatternTable[i];
}

olc::Pixel& olc2C02::GetColourFromPaletteRam(uint8_t palette, uint8_t pixel)
{
	// Gives appropriate screen colour based on a specified palette and pixel index.
	return palScreen[ppuRead(0x3F00 + (palette << 2) + pixel) & 0x3F];
}


