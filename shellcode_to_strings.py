#!/usr/bin/python3

import argparse
import subprocess
import re

READELF_ARGV = ["readelf", "-x", ".text"]

def main():
	parse_args()
	completed = subprocess.run(READELF_ARGV, stdout=subprocess.PIPE)
	readelf_output = completed.stdout.decode("utf-8")
	readelf_output = readelf_output.split('\n')

	output_string = ""
	for x in readelf_output[2:]:
		output_string += ''.join(x.split(" ")[3:7])

	output_string = bytes.fromhex(output_string)
	for i in range(0, len(output_string), 16):
		print('shellcode += \'\\x' + '\\x'.join(hex(char)[2:].zfill(2) for char in output_string[i:i+16]) + '\'')

	print("")

	print("char *shellcode = \"", end = '', flush=True)
	for i in range(0, len(output_string)):
		print("\\x%02x" % output_string[i], end='', flush=True)

	print("\"")

def parse_args():
	parser = argparse.ArgumentParser(description="Dumps shellcode from binary's main functon")
	parser.add_argument('--binary', dest='bin', required=True, help='Target ELF Binary')
	args = parser.parse_args()
	global READELF_ARGV
	READELF_ARGV.append(args.bin)

if __name__ == "__main__":
	main()
