import random

# Predefined variables
name = "Bot Number 286"
monsoon = "rainy"
mood = "Smiley"

# Dictionary of possible user inputs and bot responses
resp = {
    "what's your name?": [
        "They call me {0}".format(name),
        "I usually go by {0}".format(name),
        "My name is the {0}".format(name)
    ],
    "what's today's weather?": [
        "The weather is {0}".format(monsoon),
        "It's {0} today".format(monsoon)
    ],
    "how are you?": [
        "I am feeling {0}".format(mood),
        "{0}! How about you?".format(mood),
        "I am {0}! How about yourself?".format(mood)
    ],
    "": [
        "Hey! Are you there?",
        "What do you mean by these?"
    ],
    "default": [
        "I'm not sure how to respond to that.",
        "Can you rephrase that?",
        "I didn't understand that."
    ]
}

# Response function
def res(message):
    if message in resp:
        return random.choice(resp[message])
    else:
        return random.choice(resp["default"])

# Mapping input to known questions
def real(xtext):
    if "name" in xtext:
        return "what's your name?"
    elif "weather" in xtext or "monsoon" in xtext:
        return "what's today's weather?"
    elif "how are" in xtext:
        return "how are you?"
    else:
        return ""

# Sending message and getting response
def send_message(message):
    print("You:", message)
    response = res(message)
    print("Bot:", response)

# Chat loop
print("BOT: Hello! I am a simple chatbot. Ask me something or type 'exit' to end.")

while True:
    my_input = input().lower()
    if my_input in ["exit", "stop"]:
        print("Bot: Goodbye!")
        break
    related_text = real(my_input)
    send_message(related_text)
