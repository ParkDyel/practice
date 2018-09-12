import graphene
from .fields import HelloField

default_value = "Lewis"

class Query(graphene.ObjectType):
    Hello = graphene.String(of_type=HelloField,
                            name=graphene.String(default_value=default_value))

    # 리솔버
    @staticmethod
    def resolve_hello(root, info, name):
        return "Hello " + name