# Convert Binary to Hex (via Decimal)
binary = "11010110"
decimal = int(binary, 2)
hexa = hex(decimal)
print(f"Binary to Hexadecimal of {binary} = {hexa[2:].upper()}")
