# Convert Hex to Binary (via Decimal)
hexa = "D6"
decimal = int(hexa, 16)
binary = bin(decimal)
print(f"Hexadecimal to Binary of {hexa} = {binary[2:]}")
