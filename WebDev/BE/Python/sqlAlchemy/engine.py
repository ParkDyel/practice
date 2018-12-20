from sqlAlchemy import sqlAlchemy
from sqlAlchemy import create_engine

# db = {
#     'dialect' : 'mysql',
#     'id' : 'root',
#     'pswd' : '1234',
#     'ip' : 'localhost',
#     'dbName' : 'test'
# }

engine = create_engine('mysql://scott:tiger@localhost/test')
connection = engine.connect()
result = connection.execute("select * from users")
for row in result:
    print(row)
connection.close()
result.close()