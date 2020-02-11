from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
	return render_template('home.html')


@app.route('/about')
def about():
	return render_template('about.html')


@app.route('/projects/medit')
def medit():
	return render_template('projects/medit.html')


@app.route('/projects/web')
def web():
	return render_template('projects/web.html')


if __name__ == "__main__":
	app.run(host="localhost", port=80, debug=True)

