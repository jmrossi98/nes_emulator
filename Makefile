build: .PHONY
	g++ -g main.cpp -o RETRoNES.exe src\\Bus.cpp src\\cpu\\olc6502.cpp src\\ppu\\olc2C02.cpp src\\cartridge\\Cartridge.cpp src\\mapper\\Mapper.cpp src\\mapper\\Mapper_000.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

.PHONY: