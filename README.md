# Harvard CS50
course labs and problemsets

Contains files:

### Algorithm 
- **crack.c** is brutal force password crack for searching password for DES hash. Maximum lengh of pasword is 5 characters.
- **brut.c** searching password for DES hash with dictionary of most used passwords. Dictionary file should be named "dict.txt" and placed in the same directory.
- **factorial.c** using recursion for calculating factorial 
- 
### Basic
folder contains programs created for general syntactics practice
- **hello.c** request NAME and print : "hello,  NAME".
- **mario1.c**  builds pyramid made by # simbol. Used for practice in cycles.
- **mario2.c** is more complicate variation of pyramid.
- **readability.c** request text than determine Coleman-Liau index of the text
- **cash.c** calculate how many coins needed for pay rest. User for practice condition operators.
- **credit.c** check credit card number velidity by Luhn algorithm and determine payment system
- **caesar.c**  incripts string with Caesar cipher. Command line argument used for transfer a Key number.
- **plurality.v** program that runs a plurality election
- **runoff.c** program that runs a runoff election
- **scrabble.c** compares  words scores and print winner.
- **vigenere.c** incripts string with Vigenere cipher. Command line argument used for transfer a Key word.
- **volume.c** modifies the volume of an audio file
- **substitution.c** incript message based on simple substitution code, substitution alphabet should be provided as argument in comand line.

### Image
folder contains programs for processing images:
- **whodunit.c**  - remove red noise from image. Image format is not compressed 24-bit BMP file. Requires bmp.h .  clue.bmp can be used as test file - put it as first argument (intfile.bmp)
- **resize.c** - resizes a not compressed 24-bit BMP file. usage format:  *./resize ratio infile outfile*. Requires bmp.h
- **recover.c** - recovers deleted jpg images stored in FAT file system. Usage format: *./recover rawimagefile.* File **card.raw** can be used as test rawimagefile file.  
- **filter-bmp.zip** -contains source files for filtering bmp image. Usage format: *./filter [option] soursefile outfile*. [option] can be: **-b** for blur, **-e** for define edges, **-g** for make picture graycolor, **-r** for reflection

### speller-hashtable
folder contains program that spell-checks a file using hashed dictionary.
Usage: *./speller dictionaryfile textfile*.

*large.dic* can be used as dictionary file by default.
*lalaland.txt* can be used as text file example
