# Convert Binary to Octal (via Decimal)
binary = "110101"
decimal = int(binary, 2)
octal = oct(decimal)
print(f"Binary to Octal of {binary} = {octal[2:]}")
