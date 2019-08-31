from flask import Flask
from graphene import GraphQLView

from lib.schema import schema

app = Flask(__name__)

app.add_url_rule('/graphql', view_func=GraphQLView.as_view('graphql', schema=schema, graphiql=True))

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)