#!/usr/bin/python3

import argparse
import subprocess
import re

READELF_ARGV = ["readelf", "-x", ".text"]
OUTPUT_LANG = ""

def main():
	parse_args()
	completed = subprocess.run(READELF_ARGV, stdout=subprocess.PIPE)
	readelf_output = completed.stdout.decode("utf-8")
	readelf_output = readelf_output.split('\n')

	output_string = ""
	for x in readelf_output[2:]:
		output_string += ''.join(x.split(" ")[3:7])

	output_string = bytes.fromhex(output_string)

	if (OUTPUT_LANG is "py"):
		for i in range(0, len(output_string), 16):
			print('shellcode += \'\\x' + '\\x'.join(hex(char)[2:].zfill(2) for char in output_string[i:i+16]) + '\'')

	elif (OUTPUT_LANG is "c"):
		prefix = ""
		print("char *shellcode = ", end='', flush=True)
		for i in range(0, len(output_string), 16):
			if i != 0:
				prefix = "\t\t"
			print(prefix + "\"" + '\\x'.join(hex(char)[2:].zfill(2) for char in output_string[i:i+16]) + "\"", end='')
			if i + 16 >= len(output_string):
				print(";")
			else:
				print("")

def parse_args():
	parser = argparse.ArgumentParser(description="Dumps shellcode from binary's main functon")
	parser.add_argument('--binary', dest='bin', required=True, help='Target ELF Binary')
	parser_group = parser.add_mutually_exclusive_group(required=True)
	parser_group.add_argument('--c', action='store_true', help='Output C String')
	parser_group.add_argument('--python', action='store_true', help='Output Python String')
	args = parser.parse_args()
	global READELF_ARGV
	READELF_ARGV.append(args.bin)
	global OUTPUT_LANG
	if (args.c):
		OUTPUT_LANG = "c"
	elif (args.py):
		OUTPUT_LANG = "py"

if __name__ == "__main__":
	main()
