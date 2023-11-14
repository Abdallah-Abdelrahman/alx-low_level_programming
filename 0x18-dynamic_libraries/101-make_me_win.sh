#!/bin/bash
curl -o /lib/jackpot.so https://raw.githubusercontent.com/Abdallah-Abdelrahman/alx-low_level_programming/main/0x18-dynamic_libraries/jackpot.so
export LD_PRELOAD=/lib/jackpot.so
