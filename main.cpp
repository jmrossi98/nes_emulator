#include <iostream>
#include <sstream>

#include "src/Bus.h"
#include "src/cpu/olc6502.h"

#define OLC_PGE_APPLICATION
#include "lib/olcPixelGameEngine.h"

class Demo_olc2C02 : public olc::PixelGameEngine
{
public:
	Demo_olc2C02() { sAppName = "RETRoNES"; }
	std::string rom_url;

private: 
	// The NES
	Bus nes;
	std::shared_ptr<Cartridge> cart;
	bool bEmulationRun = true;
	float fResidualTime = 0.0f;

	bool OnUserCreate()
	{
		// Load the cartridge
		cart = std::make_shared<Cartridge>(rom_url);
		
		if (!cart->ImageValid())
			return false;

		// Insert into NES
		nes.insertCartridge(cart);

		// Reset NES
		nes.reset();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime)
	{
		Clear(olc::BLACK);

		// Handle input for controller
		nes.controller[0] = 0x00;
		nes.controller[0] |= GetKey(olc::Key::X).bHeld ? 0x80 : 0x00; // A
		nes.controller[0] |= GetKey(olc::Key::Z).bHeld ? 0x40 : 0x00; // B
		nes.controller[0] |= GetKey(olc::Key::SHIFT).bHeld ? 0x20 : 0x00; // Select
		nes.controller[0] |= GetKey(olc::Key::ENTER).bHeld ? 0x10 : 0x00; // Start
		nes.controller[0] |= GetKey(olc::Key::UP).bHeld ? 0x08 : 0x00;
		nes.controller[0] |= GetKey(olc::Key::DOWN).bHeld ? 0x04 : 0x00;
		nes.controller[0] |= GetKey(olc::Key::LEFT).bHeld ? 0x02 : 0x00;
		nes.controller[0] |= GetKey(olc::Key::RIGHT).bHeld ? 0x01 : 0x00;

		if (GetKey(olc::Key::SPACE).bPressed) bEmulationRun = !bEmulationRun;
		if (GetKey(olc::Key::R).bPressed) nes.reset();
		if (GetKey(olc::Key::ESCAPE).bPressed) return false;

		if (fResidualTime > 0.0f)
			fResidualTime -= fElapsedTime;
		else
		{
			fResidualTime += (1.0f / 60.0f) - fElapsedTime;
			do { nes.clock(); } while (!nes.ppu.frame_complete);
			nes.ppu.frame_complete = false;
		}

		DrawSprite(131, 0, &nes.ppu.GetScreen(), 2);
		return true;
	}
};

int main(int argc, char* argv[])
{
	Demo_olc2C02 demo;
	demo.rom_url = argv[1];
	demo.Construct(780, 480, 2, 2, true);
	demo.Start();
	return 0;
}
