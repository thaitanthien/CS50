from sys import argv, exit
import csv


# Function that calculate the maximun number of times a substring is repeated
def max_time_substring_repeat(s, sub):
    ans = [0] * len(s)      # len(s) array with 1 element
    for i in range(len(s) - len(sub), -1, -1):  # for(int i = strlen(s)-strlen(sub); i > -1; i--)
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)


# Function that print out name of matching person
def print_match(reader, actual):
    for line in reader:
        # Extract names and values
        person = line[0]
        values = [int(val) for val in line[1:]]

        # Compare STRs value
        if values == actual:
            print(person)
            return
    print("No match")


def main():
    # Check for command-line argument
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    csv_path = argv[1]
    txt_path = argv[2]

    # Open CSV file and read to a list
    with open(csv_path, "r") as csv_file:
        reader = csv.reader(csv_file)
        # Store first line except "name"
        all_STRs = next(reader)[1:]

        # Open sequence txt and read
        with open(txt_path, "r") as txt_file:
            s = txt_file.read()

            # Compute the longest run of consecutive repeats of the STRs and store it in an array
            actual = [max_time_substring_repeat(s, seq) for seq in all_STRs]

        # Find match and print name
        print_match(reader, actual)


# Call main function
if __name__ == "__main__":
    main()