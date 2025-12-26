## Quick Tips

This page will be improved by time

for now here some quick details, to centralized the storage requests and avoid UWP limitations

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

---

## Cores Sources

The cores sources provided from my dev environment as-is, 

please don't ask of any core's related issue as I don't cover that,

you need to maintain them on your own, and handle/fix issue by your self

to save your time, they don't generally have big changes, few MSVC fixes, 

along the part that forward some requests to ImMobile environment, 

which usually replace the original API with ImMobile (...Imm),

also the VFS part is totally handled by ImMobile & ImLibretro to centralized the requests,

I don't use Libretro way for VFS instead ImMobile has storage resolver,

the resolver made with thousands of lines to fix UWP access on legacy builds 8.1+, 

so it's not a simple layer can be replaced, and it help for in-place files picker.

Also ImMobile handle a lot of memory management (internally) which help memory map calls.

I developed my own tool that parse make file and build up proper structure to compile,

this tool is for my private usage, you need to deal with the compile part from your own side,

also there is tedious part of the job I do usually manually to maintain includes & flags for MSVC.