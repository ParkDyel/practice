from flask import Flask
from flask_graphql import GraphQLView

# from database import db_session
from GraphQL.schema import schema
from GraphQL.data import *

# Test 1
result = schema.execute('''
query{
    hello
}''')
print(result.data['hello']) # "Hello stranger"

result = schema.execute('''{
mutation Nutation 
    }''')
print(result.data['name']) # "Hello stranger"


# app = Flask(__name__)

# DEBUG_ENABLE = 1

# @app.route('/')
# def hello_world():
#     return 'Hello, World!'

# app.add_url_rule('/graphql', view_func=GraphQLView.as_view('graphql', schema=schema, graphiql=True))

# if __name__ == "__main__":
#     app = Flask(__name__)
#     app.run(host='0.0.0.0', port=8080, debug=DEBUG_ENABLE)
