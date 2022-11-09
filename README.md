Pixel Space Game
---
Space game rendered in pixel-art style, or like an old retro game. Testing ground for C++ w/ Godot. Want to try out procedural generation and other things.

Envision the game to play like M&B but in space, or like a singleplayer Eve game, also heavily influenced by Elite Dangerous and Dwarf Fortress.

Cloning
---
After cloning the repository, make sure the submodules are on the correct branch (synced w/ godot version). 
Then run `git submodule update --init --recursive` to initialize the submodules.

Building
---
1. In order to build the project open the **x64 Native Tools Command Prompt**, cd into the godot-cpp directory, and run the command:  
`scons platform=<platform> generate_bindings=yes -j4 bits=64`  
> **Note:** On non windows systems, must have appropriate C++ build tools installed. On x86 systems can remove the `bits`.

2. After all changes are ready to be compiled, run the below command from the root of the project.  
`scons [target=release| r | debug | d] platform=(windows|x11|linux|osx)`
3. Verify files have been built to `project/bin/<platform>/` and then run the project from Godot.