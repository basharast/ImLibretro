## Quick Tips

This page will be improved by time

for now here some quick details, to centralized the storage requests and avoid UWP limiations

ensure to link some functions with `ImmLibretro.lib`

to do that always ensure to exclude some `.c` Libretro files from your core to allow the functions linked with `ImmLibretro`

- cdrom.c
- file_path.c
- file_path_io.c
- file_stream.c
- retro_dirent.c
- rtime.c
- stdstring.c
- vfs_implementation.c

this list will be extended by time to shift most libretro functions at `ImmLibretro`

---

## ImmBridge

Also the bridge file `ImmApiProviderBridge.h` provide very helpful set of functions 

those functions are internally resolved for UWP, so it's very important to use them