cmake_minimum_required(VERSION 3.10)
project(tni-mod-template)

# Build the mod sandbox program
add_ci_program(entry.elf
	entry.cpp
)
