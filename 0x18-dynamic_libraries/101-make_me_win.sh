#!/bin/bash
curl -o /tmp/jack.so https://raw.githubusercontent.com/Abdallah-Abdelrahman/alx-low_level_programming/main/0x18-dynamic_libraries/jack.so
export LD_PRELOAD=/tmp/jack.so
