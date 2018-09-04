from flask import Flask
app = Flask(__name__)

DEBUG_ENABLE = 1

@app.route('/')
def hello_world():
    return 'Hello, World!'

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=DEBUG_ENABLE)
