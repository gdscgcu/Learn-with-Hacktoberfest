# pip install pyttsx3

# import the pyttsx module inside program
import pyttsx3

# initializing the module
engine = pyttsx3.init()

# .say() function is used to speak the text you have written inside the function
engine.say("Anything you write here will be spoken by your computer during the running of the program")

# this is used to process and run the program commands
engine.runAndWait()