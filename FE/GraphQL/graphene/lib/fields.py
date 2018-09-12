import graphene

class HelloField(graphene.ObjectType):
    answer = graphene.String()