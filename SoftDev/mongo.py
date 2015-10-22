import random
from pymongo import Mongo Client

# connection = MongoClient("hostname")
connection = MongoClient();

# for authentication
# db = connection.admin
# db.authenticate("username", "password")

# we could also have done: db = connection.pd7
db = connection['pd7']

print db.collection_names()
