from nltk.chat.util import Chat, reflections

pairs = [
    [r"my name is (.)", ["Hello %1, How are you"]]
]

print("Hey there! I am Robot 2.0 at your service")
chat = Chat(pairs, reflections)
chat.converse()
