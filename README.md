# Cyphers

This repo contains several cyphers designed by my own at 2002-2006.

1. First try was "Enigma" - console application, which encodes any ASCII text. Each char is represented with sequence of 8 number value, depend of initial placement and characters of initial text. This code is substitutional-like cypher. Output of enigma is *.cod file. App encodes/decodes files. This is console app (C++), initially for Windows. Developed around 2002.

![Enigma cypher result](https://github.com/wwakabobik/cyphers/blob/master/enigma/enigma_cod.png)

2. DOS_creator, as it named, creates "Data Object Secure" file format, which links *.cod files in one sequence, nothing special. This is console app (C++), initially for Windows. Developed around 2003-2004 and encorporated into [TDSV Viewer](https://github.com/wwakabobik/tdsv_viewer) (as well as enigma encoder/decoder).

3. UDEC - It's another substitutional-shift cypher, based on char values itself (devide factor). App encodes/decodes input strings, not files. This is Windows GUI app was developed in Borland C++ Builder 6 in 2004-2005.

![Udec interface](https://github.com/wwakabobik/cyphers/blob/master/udec/udec.png)

4. Cypher - it's vector-based cypher. User defines two unique strings: one is 8 number digit, and second is 8 char lingth string. This vectors used as indexes for 8x8 matrix of ASCII chars(256). So, as result of cypehring, there will be i, j indexes of initial vectors (represent placement of char in table), what will produce encoded text twice longer than initial. App encodes/decodes files. This app was developed in C++ approx in 2003-2004 as console application, and was refactored to Windows GUI application (Borland C++ Builder 6) in 2004-2005. [Link to binary](http://illusionist7.narod.ru/download/PROGS/udec.rar).

![Cypher interface](https://github.com/wwakabobik/cyphers/blob/master/cypher/cypher.png)

5. RSA - it's my try to implement world-known cryptosystem. It's console app developed around 2006 using C++, initially for Windows.
