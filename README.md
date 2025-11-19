# Tower Networking Inc. Modding Kit

This repository is a modding kit that can be used to create mods for the game [Tower Networking Inc](https://store.steampowered.com/app/2939600/Tower_Networking_Inc/). Mods are currently written in C/C++. Modding support for the game is currently implemented with [Godot Sandbox](https://github.com/libriscv/godot-sandbox) using [libriscv](https://libriscv.no/).

Note that modding for the game is still in early design/implementation stage, and any feedback/suggestions is encouraged to make modding the game fun!

## Example mods

Examples are your friend. To get started, take a look at the following examples:

### Template mod

The [Template mod](/programs/tni-mod-template) is a template that contains the common use scenario for writing a mod.

## Building mods

Check out the (docs)[https://libriscv.no/docs/host_langs/godot_integration/godot_docs/cmake#cmake-setup] on librisc-v for more information

### Windows

Make sure the following is installed:

1. Install [CMake](https://cmake.org/download/).
2. Install [Ninja](https://ninja-build.org/) (recommended for fast builds).
3. Install [Zig](https://ziglang.org/download/) (required for RISC-V cross-compilation).

On the root of this project, run the command:

```
zig.cmd
```

The built output (a .elf file) will be in the `.zig/<name-of-your-mod>/entry.elf` directory.

## Loading the mod

Mods in the game will be loaded from the user's game directory.

Windows: `%APPDATA%\Godot\app_userdata\Tower Networking Inc`
Linux: `~/.local/share/godot/app_userdata/Tower Networking Inc`

On the user's game directory, you'll observe directories like `saves/` and `logs/`. Place your mod in the `mods/` directory.

For example, to install the `tni-mod-template` mod, place `.zig/tni-mod-template` to `mods/` such that `mods/tni-mod-template/entry.elf` exists.

Mods are loaded/run in alphabetical ordering.