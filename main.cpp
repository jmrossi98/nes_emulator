#include <iostream>
#include <sstream>
#include <deque>

#include "Bus.h"

#define OLC_PGE_APPLICATION
#define OLC_PGEX_SOUND
#include "olcPixelGameEngine.h"
#include "olcPGEX_Sound.h"

class Emulator : public olc::PixelGameEngine
{
public:
	Emulator() { sAppName = "RETRoNES"; }
	std::string rom_url;

private: 
	Bus nes;
	std::shared_ptr<Cartridge> cart;
	bool bEmulationRun = true;
	float fResidualTime = 0.0f;
	uint8_t nSelectedPalette = 0x00;
	std::list<uint16_t> audio[4];
	float fAccumulatedTime = 0.0f;

private:
	// The NES
	static Emulator* instance;
	static float SoundOut(int nChannel, float fGlobalTime, float fTimeStep)
	{
		if (nChannel == 0)
		{
			while (!instance->nes.clock()) {};
			return static_cast<float>(instance->nes.dAudioSample);
		}
		else
			return 0.0f;
	}

	bool OnUserCreate() override
	{
		// Load the cartridge
		cart = std::make_shared<Cartridge>(rom_url);
		
		if (!cart->ImageValid())
			return false;

		// Insert into NES
		nes.insertCartridge(cart);

		for (int i = 0; i < 4; i++)
		{			
			for (int j = 0; j < 120; j++)
				audio[i].push_back(0);
		}

		// Reset NES
		nes.reset();

		// Initialize PGEX sound system
		instance = this;
		nes.SetSampleFrequency(44100);
		olc::SOUND::InitialiseAudio(44100, 1, 8, 512);
		olc::SOUND::SetUserSynthFunction(SoundOut);
		return true;
	}

	bool OnUserDestroy() override
	{
		olc::SOUND::DestroyAudio();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		fAccumulatedTime += fElapsedTime;
		if (fAccumulatedTime >= 1.0f / 60.0f)
		{
			fAccumulatedTime -= (1.0f / 60.0f);
			audio[0].pop_front();
			audio[0].push_back(nes.apu.pulse1_visual);
			audio[1].pop_front();
			audio[1].push_back(nes.apu.pulse2_visual);
			audio[2].pop_front();
			audio[2].push_back(nes.apu.noise_visual);
		}

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

		DrawSprite(131, 0, &nes.ppu.GetScreen(), 2);
		return true;
	}
};

Emulator* Emulator::instance = nullptr;

int main(int argc, char* argv[])
{
	Emulator emulator;
	emulator.rom_url = argv[1];
	emulator.Construct(780, 480, 2, 2);
	emulator.Start();
	return 0;
}
