from flask import Flask
from flask_graphql import GraphQLView
from lib.schema import schema

app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

app.add_url_rule('/graphql', view_func=GraphQLView.as_view('graphql', schema=schema, graphiql=True))

if __name__ == "__main__":
    app.run(debug=True)