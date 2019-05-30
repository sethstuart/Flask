from flask import Flask
why = Flask(__name__)

@why.route("/")
def hello():
    return "Oh god oh fuck I want to die."