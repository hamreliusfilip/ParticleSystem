Package: catch2[core]:x64-osx -> 3.2.1

**Host Environment**

- Host: x64-osx
- Compiler: AppleClang 14.0.0.14000029
-    vcpkg-tool version: 2023-01-24-8a88d63f241d391772fbde69af9cab96c3c64c75
    vcpkg-scripts version: 36fb23307 2023-02-10 (3 days ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Downloading https://github.com/catchorg/Catch2/archive/v3.2.1.tar.gz -> catchorg-Catch2-v3.2.1.tar.gz...
-- Extracting source /Users/filiphamrelius/Documents/TNM094/vcpkg/downloads/catchorg-Catch2-v3.2.1.tar.gz
-- Applying patch fix-install-path.patch
-- Using source at /Users/filiphamrelius/Documents/TNM094/vcpkg/buildtrees/catch2/src/v3.2.1-3402b475e3.clean
-- Configuring x64-osx
-- Building x64-osx-dbg
-- Building x64-osx-rel
-- Fixing pkgconfig file: /Users/filiphamrelius/Documents/TNM094/vcpkg/packages/catch2_x64-osx/lib/pkgconfig/catch2-with-main.pc
-- Fixing pkgconfig file: /Users/filiphamrelius/Documents/TNM094/vcpkg/packages/catch2_x64-osx/lib/pkgconfig/catch2.pc
CMake Error at scripts/cmake/vcpkg_find_acquire_program.cmake:617 (message):
  Could not find pkg-config.  Please install it via your package manager:

      brew install pkg-config
Call Stack (most recent call first):
  scripts/cmake/vcpkg_fixup_pkgconfig.cmake:197 (vcpkg_find_acquire_program)
  buildtrees/versioning_/versions/catch2/43e022b806928c512e298052ad4fae210998a846/portfile.cmake:26 (vcpkg_fixup_pkgconfig)
  scripts/ports.cmake:147 (include)



```


**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "name": "particlesystem",
  "version-string": "0.0.1",
  "homepage": "https://gitlab.liu.se/tnm094-labs/particlesystem",
  "license": "BSD-2-Clause",
  "vcpkg-configuration": {
    "default-registry": {
      "kind": "builtin",
      "baseline": "92225e6ce480662b29319d8e917d253976407247"
    }
  },
  "dependencies": [
    "catch2",
    "fmt",
    "glad",
    "glfw3",
    "glm",
    {
      "name": "imgui",
      "features": [
        "glfw-binding",
        "opengl3-binding"
      ]
    },
    {
      "name": "tracy",
      "features": [
        "gui-tools"
      ],
      "platform": "!linux"
    },
    {
      "name": "tracy",
      "platform": "linux"
    }
  ]
}

```
</details>
