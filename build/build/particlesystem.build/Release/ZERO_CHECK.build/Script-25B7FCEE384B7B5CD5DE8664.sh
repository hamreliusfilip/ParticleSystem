#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/filiphamrelius/Documents/TNM094/build
  make -f /Users/filiphamrelius/Documents/TNM094/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/filiphamrelius/Documents/TNM094/build
  make -f /Users/filiphamrelius/Documents/TNM094/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/filiphamrelius/Documents/TNM094/build
  make -f /Users/filiphamrelius/Documents/TNM094/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/filiphamrelius/Documents/TNM094/build
  make -f /Users/filiphamrelius/Documents/TNM094/build/CMakeScripts/ReRunCMake.make
fi

