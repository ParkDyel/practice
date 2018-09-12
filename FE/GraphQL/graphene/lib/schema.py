import graphene
from flask_graphql import GraphQLView
from .mutation import Mutation
from .query import Query

schema = graphene.Schema(query=Query, mutation=Mutation)