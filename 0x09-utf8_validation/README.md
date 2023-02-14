# 0x09-utf8_validation

## 0. UTF-8 Validation
Write a method that determines if a given data set represents a valid UTF-8 encoding.

- Prototype: def validUTF8(data)
- Return: True if data is a valid UTF-8 encoding, else return False
- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

### UTF-8 Validation Rules:
- 4 x 8 = 32 digits, 4 bytes maximum
- For a 1-byte character, the first bit is a 0, followed by its Unicode code.
- For n-bytes character, the first n-bits are all ones, the n+1 bit is 0, followed by n-1 bytes with the most significant 2 bits being 10.

|First code point|Last code point|Byte 1  |Byte 2  |Byte 3  |Byte 4  |Code points|
|----------------|---------------|--------|--------|--------|--------|-----------|
|U+0000          |U+007F         |0xxxxxxx|        |        |        |128        |
|U+0080          |U+07FF         |110xxxxx|10xxxxxx|        |        |1920       |
|U+0800          |U+FFFF         |1110xxxx|10xxxxxx|10xxxxxx|        |61440      |
|U+10000         |U+10FFFF       |11110xxx|10xxxxxx|10xxxxxx|10xxxxxx|1048576    |

