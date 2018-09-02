from flask import Flask
from flask_graphql import GraphQLView

# from database import db_session
from GraphQL.schema import schema
from GraphQL.data import *

# Data Setup
setup()

# Test 1
result = schema.execute('query{ hello }')
print(result.data['hello']) # "Hello stranger"

# DEBUG_ENABLE = 1

# @app.route('/')
# def hello_world():
#     return 'Hello, World!'

# if __name__ == "__main__":
#     app = Flask(__name__)
#     app.add_url_rule('/graphql', view_func=GraphQLView.as_view('graphql', schema=schema, graphiql=True, context={'session': db_session}))
#     app.run(host='0.0.0.0', port=8080, debug=DEBUG_ENABLE)
