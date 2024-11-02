//  1.4.Wenowconsidertherelationbetweenpasswordsandkeysize.Forthispurpose
//  weconsideracryptosystemwheretheuserentersakeyintheformofapassword.
//  1.Assumeapasswordconsistingof8letters,whereeachletter isencodedbythe
//  ASCIIscheme(7bitspercharacter, i.e.,128possiblecharacters).What is the
//  sizeofthekeyspacewhichcanbeconstructedbysuchpasswords?
//  2.Whatisthecorrespondingkeylengthinbits?
//  3.Assumethatmostusersuseonlythe26lowercaselettersfromthealphabet in
// steadof thefull7bitsof theASCII-encoding.What is thecorrespondingkey
//  lengthinbitsinthiscase?
//  4.Atleasthowmanycharactersarerequiredforapasswordinordertogeneratea
//  keylengthof128bitsincaseoflettersconsistingof
//  a.7-bitcharacters?
//  b.26lowercaselettersfromthealphabet?


// ANswers 
// Size of key space with 8 ASCII characters (7 bits per character):


// Each character can have 2^7 = 128 possible values
// For 8 characters, total combinations = 128^8
// Key space = 128^8 = 2^56 possible passwords


// Key length in bits:


// Since key space is 2^56
// Key length = 56 bits


// With only 26 lowercase letters:


// Each character can only have 26 possibilities
// For 8 characters, total combinations = 26^8
// To convert to bits: 2^x = 26^8
// Taking log base 2: x = log2(26^8)
// x = 8 * log2(26) ≈ 37.6 bits
// So the effective key length is about 37.6 bits


// Characters needed for 128-bit key:
// a. Using 7-bit ASCII characters:


// Let n be number of characters
// 7n = 128 (we need 128 bits total)
// n = 128/7 ≈ 18.29
// Round up to 19 characters needed

// b. Using 26 lowercase letters:

// Let n be number of characters
// n * log2(26) = 128
// n = 128/log2(26)
// n = 128/4.7 ≈ 27.23
// Round up to 28 characters needed

// Therefore:

// For 7-bit ASCII: 19 characters needed
// For lowercase letters only: 28 characters needed