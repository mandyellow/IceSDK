# IceSDK
IceSDK is a cold little Game SDK to create games You can use individuel parts or
just use it as a Game Engine itself.


## How to setup
Setting things up is quite easy, you simply go ahead and run following commands:
```sh
# Clone the repository
git clone https://github.com/Mempler/IceSDK


# Generate IDE Specific files
# those are the supported args:
# --ide=(`vscode`, `vs2017`, `vs2019`) --target?=(`android`, `emscripten`)
# though android doesn't really work right now.
python3 ./tools/setup.py --ide=vscode
```

## Manuel Setup
Manuel setup isn't really supported, if you want to know how it works,
please checkout .ide and or .github/workflows

## Supported Platforms
Current supported platforms:
iOS/MacOS aren't currently supported since i lack those devices.

| ![Windows](./.assets/windows_64x64.png) | ![Linux](./.assets/linux_64x64.png) | ![osX](./.assets/osx_64x64.png) | ![android](./.assets/android_64x64.png) | ![ios](./.assets/ios_64x64.png) | ![web](./.assets/wasm_64x64.png) |
| --------------------------------------- | ----------------------------------- | ------------------------------- | --------------------------------------- | ------------------------------- | -------------------------------- |
| :heavy_check_mark:                      | :heavy_check_mark:                  | :x:                             | :heavy_check_mark:                      | :x:                             | :heavy_check_mark:               |

## Compile Status

| Platform   | Windows                                                                                             | Linux                                                                                               | MacOS |
| ---------- | --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- | ----- |
| PC         | ![GitHub Workflow Status](https://github.com/Mempler/IceSDK/workflows/PC%20Windows/badge.svg)       | ![GitHub Workflow Status](https://github.com/Mempler/IceSDK/workflows/PC%20Linux/badge.svg)         | :x:   |
| Android    | ![GitHub Workflow Status](https://github.com/Mempler/IceSDK/workflows/Win32%20Android/badge.svg)    | ![GitHub Workflow Status](https://github.com/Mempler/IceSDK/workflows/Linux%20Android/badge.svg)    | :x:   |
| iOS        | :x:                                                                                                 | :x:                                                                                                 | :x:   |
| Emscripten | ![GitHub Workflow Status](https://github.com/Mempler/IceSDK/workflows/Win32%20Emscripten/badge.svg) | ![GitHub Workflow Status](https://github.com/Mempler/IceSDK/workflows/Linux%20Emscripten/badge.svg) | :x:   |
