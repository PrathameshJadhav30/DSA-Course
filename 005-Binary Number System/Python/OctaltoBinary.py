# Convert Octal to Binary (via Decimal)
octal = "65"
decimal = int(octal, 8)
binary = bin(decimal)
print(f"Octal to Binary of {octal} = {binary[2:]}")
