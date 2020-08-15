from flask import (Flask, render_template)

app = Flask("__main__")

@app.route("/")
def index():
    return render_template("index.html", flask_token="Hello, world!")

if __name__ == "__main__":
    app.run(debug=True)
