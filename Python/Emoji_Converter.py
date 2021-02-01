emojis={
    ":)" : "😊",
    ":(" : "😔"
}

massage = input("> ")
word = massage.split(' ')

output = ""
for w in word:
    output+=emojis.get(w,w)+' '
print(output)


massage = input("> ")
word = massage.split(' ')

output = ""
for w in word:
    output+=emojis.get(w,w)+' '
print(output)