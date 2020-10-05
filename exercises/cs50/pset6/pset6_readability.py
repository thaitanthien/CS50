from cs50 import get_string
# This program computes the approximate grade level needed to comprehend some text

# Input the text
text = get_string("Text: ")

words = 0
sentences = 0
letters = 0

for i in range(len(text)):
    # Number of letters
    # if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
    if text[i].isalpha():
        letters += 1
    # Number of sentences
    elif text[i] in ['.', '!', '?']:
        sentences += 1
    # Number of words
    elif text[i] == ' ':
        words += 1
words += 1

# Coleman-Liau index
L = letters * 100 / words
S = sentences * 100 / words
index = round(0.0588 * L - 0.296 * S - 15.8)

# Output the result
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")