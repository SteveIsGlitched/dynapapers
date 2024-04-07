<div align="center">

# Dynapapers

[![Dynapapers](https://github.com/SteveIsGlitched/dynapapers/actions/workflows/dynapapers.yml/badge.svg)](https://github.com/SteveIsGlitched/dynapapers/actions/workflows/dynapapers.yml) 
![C++ - 100%](https://img.shields.io/static/v1?label=C%2B%2B&message=100%&color=blue) 
![License - GPL-3.0](https://img.shields.io/static/v1?label=License&message=GPL-3.0&color=red)

An utility used for changing wallpapers dynamically. This was created as a hobby beginning project, and is at very early development stage. Uses [nlohmann/json](https://github.com/nlohmann/json) library for config parsing.

## Installation
G++ is needed for compiling. Clone this repository and execute `make install` in the folder.

## Usage
The config file should be located in this location: `/home/$USER/.config/dynapapers/config.json`.
```c++
{
	"silent": false,
	
	"path": "/home/steveisglitched/Documents/24h/",
	"cmd": "swww img ",
	"fileExtensions": ".png",
	
	"updateInterval": 50
}
```
The program will update wallpapers depending on current hour, for example if right now is 15:25, it will find picture called `15.png` in the `path` directory, specified in config. The program will check current hour every `updateInterval` seconds.

</div>
