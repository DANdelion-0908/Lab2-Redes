import sys
from py_modules.checksum import checksum
from py_modules.convolucionales import convolucionales
from py_modules.hamming import hamming

if __name__ == "__main__":

    if len(sys.argv) == 3:

        algorithm = sys.argv[1].lower()
        binary_string = sys.argv[2]

        if algorithm == "hamming":
            hamming(binary_string)

        elif algorithm == "convolucionales":
            convolucionales(binary_string)

        elif algorithm == "checksum":
            checksum(binary_string)

        else:
            print("Invalid algorithm")
            print("Usage: python get_strings_sys.py <hamming|convolucionales|checksum> <binary_string>")
            sys.exit(1)

    else:
        print("Usage: python get_strings_sys.py <hamming|convolucionales|checksum> <binary_string>")
        sys.exit(1) 

