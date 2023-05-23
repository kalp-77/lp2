from nltk.chat.util import Chat, reflections

pairs = [
    [r"my name is (.*)", ["Hello %1, How are you"]],
    [r"hey|hola|hi", ["hi how are you?"]]
]

chat = Chat(pairs, reflections)
chat.converse()
