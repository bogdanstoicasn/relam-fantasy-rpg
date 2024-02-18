# Input file path
input_file = "experience.txt"

# Output file path
output_file = "level.txt"

# Read data from input file
with open(input_file, 'r') as infile:
    data = infile.read().splitlines()

# Convert the factors to floats
factors = [float(factor) for factor in data]

# Initialize the current value
current_value = 200

# Calculate values based on input factors
output_data = [f"Level 1: {current_value}"]
for level, factor in enumerate(factors, start=2):
    current_value = current_value * factor  # Adding the increment to the current value
    output_data.append(f"Level {level}: {int(current_value)}")

# Write output to file
with open(output_file, 'w') as outfile:
    for line in output_data:
        outfile.write(line + '\n')

print("Output data written to:", output_file)
